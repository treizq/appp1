#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>

//Учетные записи
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "admin", "user" };
std::string* passwordArr = new std::string[userCount]{ "admin", "user" };
//----------------------


//склад
int size = 10;
int* idArr = new int[size];
int* countArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];

//----------------------
//функции
void Start();
bool Login();
void ShopUserMenu();
void ShopAdminMenu();
void ShopUserMenu();
void CreateStaticStorage();
void ShowStorage();
void RefilStorage();
void WriteOffFromStorage();
void ChangePrice();
void ChangeStaff();
void AddEmployee();
bool IsNumber(std::string string);
void EmployeeEdit();
void DeleteEmployee();
void ChangeStorage();

template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size);

template<typename ArrType>
void PrintArr(ArrType dynamicArr, int size);

#if defined(max)
#undef max
#endif



//------------------
int main()
{
	Start();
	delete[]loginArr;
	delete[]passwordArr;
	delete[]idArr;
	delete[]countArr;
	delete[]priceArr;
	delete[]nameArr;
	return 0;
}
//------------------



void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "\n\n\t\tAVI\n\n\n";



	if (Login() == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (isAdmin == true)
		{
			std::string choose;
			do
			{
				std::cout << "Использовать готовый склад или создать новый?\n";
				std::cout << "1 - готовый склад\n2 - Создать новый\n\nВвод: ";
				std::getline(std::cin, choose, '\n');
			} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);

			if (choose == "1")
			{
				CreateStaticStorage();
			}
			else
			{

			}
			ShopAdminMenu();
		}
		else
		{
			CreateStaticStorage();
			ShopUserMenu();
		}
	}
}

bool Login()
{
	while (true)
	{
		std::string login, pass;
		std::cout << "Ведите логин: ";
		std::getline(std::cin, login, '\n');
		std::cout << "Введите пароль: ";
		std::getline(std::cin, pass, '\n');

		for (int i = 1; i < userCount; i++)
		{
			if (login == loginArr[0] && pass == passwordArr[0])
			{
				std::cout << "Добро пожаловать " << loginArr[0] << '\n';
				isAdmin = true;
				return true;
			}

			else if (login == loginArr[i] && pass == passwordArr[i])
			{
				std::cout << "Добро пожаловать " << loginArr[i] << '\n';
				isAdmin = false;
				return true;
			}
		}
		system("cls");
		std::cout << "невверно введен логин или пароль!\n\n";
	}
	return true;
}

void ShopUserMenu()
{
	std::cout << "User";

}

void ShopAdminMenu()
{
	std::string choose{};
	while (true)
	{
		do
		{
			std::cout << "1. Начать продажу\n";
			std::cout << "2. Показать склад\n";
			std::cout << "3. Пополнить склад\n";
			std::cout << "4. Списать склад\n";
			std::cout << "5. Изменить цену\n";
			std::cout << "6. Изменить склад\n";
			std::cout << "7. Изменить персонал\n";
			std::cout << "8. Отчет о прибыли\n\n";
			std::cout << "0. Закрыть смену\n\n\n";
			// добавление акции 
			std::cout << "Ввод: ";
			std::getline(std::cin, choose, '\n');
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56); //промежуток asci таблицы от 0 до 8 вкл

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefilStorage();
		}
		else if (choose == "4")
		{
			WriteOffFromStorage();
		}
		else if (choose == "5")
		{
			ChangePrice();
		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{
			ChangeStaff();
		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cerr << "MainMenuErorr";
		}
	}
}

void CreateStaticStorage()
{
	const int staticSize = 10;
	int idStaticArr[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };

	std::string nameStaticArr[staticSize]
	{ "nike air force 1 white               ", "raf simons ozweego 3               ",
	  "balenciaga 3xl                    ", "nike uptempo                     ",
	  "nike x Travis Scott Air jordan 1",
	  "balenciaga 10 xl                      ", "adidas campus                   ",
	  "adidas samba                           ", "rick owens DRKSHDW               ","new rock                            "
	};

	int countStaticArr[staticSize]{ 35,3,4,8,5,2,10,10,5,5 };

	double priceStaticArr[staticSize]{ 15000.0, 140000.0, 96000.0, 20000.0, 51000.0, 120000.0, 2300.0, 11000.0, 88000.0, 52000.0 };


	SetArr(idStaticArr, idArr, staticSize);
	SetArr(nameStaticArr, nameArr, staticSize);
	SetArr(countStaticArr, countArr, staticSize);
	SetArr(priceStaticArr, priceArr, staticSize);
}

void ShowStorage()
{
	std::cout << "ID\tНазвание\t\t\t\tЦена\tКоличество\n\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t"
			<< priceArr[i] << "\t" << countArr[i] << "\n";

	}

}

void RefilStorage()
{
	std::string idStr, addStr;
	int id{}, add{};
	bool exit = false;


	while (true)
	{
		std::cout << "Введите ID товара\t0 - Выход\nВвод: ";
		std::getline(std::cin, idStr, '\n');
		if (idStr == "0")
		{
			break;
		}

		else if (IsNumber(idStr))
		{
			id = std::stoi(idStr);
			std::cout << id - 1 << "\t" << std::left << std::setw(30) << nameArr[id - 1] << '\t' << countArr[id - 1] << 'n';
			while (true)
			{
				std::cout << "Введите кол-во товара на пополнение: ";
				std::getline(std::cin, addStr, '\n');
				if (IsNumber(addStr))
				{
					add = std::stoi(addStr);
					if (add >= 0 && add < 1000)
					{
						countArr[id - 1] += add;
						std::cout << "\nТовар успешно пополнен\n\n";
						break;
					}
					else
					{
						std::cout << "\n\nНеккоректные данные\n\n";
					}
				}
				else
				{
					std::cout << "\n\nОшибка ввода\n\n";
				}
			}
			break;
		}
		else
		{
			std::cout << "\n\nОшибка ввода\n\n";
		}

	}

	/*
	std::string idStr;
	do
	{
		std::cout << "Пополнение склада\nВведите id товара: ";
		std::getline(std::cin, idStr, '\n');

		if (idStr.size() == 2 && std::stoi(idStr) <= size && std::stoi(idStr) > 0)
		{
			break;
		}

	} while (idStr.size() > 1 || std::stoi(idStr) < 0 || std::stoi(idStr) > size);



	int id = std::stoi(idStr);

	std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << "\n";

	int add{};
	do
	{
		std::cout << "Введите кол-во товара для пополнения: ";
		std::cin >> add;
	} while (add < 0 || add > MAXINT - countArr[id - 1]);

	countArr[id - 1] += add;
	std::cout << "Товар " << nameArr[id - 1] << " успешно пополнен\n\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	system("pause");
	*/
}

void WriteOffFromStorage()
{
	std::string idStr, delStr;
	int id{}, del{};
	bool exit = false;


	while (true)
	{
		std::cout << "Введите ID товара\t0 - Выход\nВвод: ";
		std::getline(std::cin, idStr, '\n');
		if (idStr == "0")
		{
			break;
		}

		else if (IsNumber(idStr))
		{
			id = std::stoi(idStr);
			std::cout << id - 1 << "\t" << std::left << std::setw(30) << nameArr[id - 1] << '\t' << countArr[id - 1] << 'n';
			while (true)
			{
				std::cout << "Введите кол-во товара на списание: ";
				std::getline(std::cin, delStr, '\n');
				if (IsNumber(delStr))
				{
					del = std::stoi(delStr);
					if (del >= 0 && del <= countArr[id - 1])
					{
						countArr[id - 1] -= del;
						std::cout << "\nТовар успешно списан\n\n";
						break;
					}
					else
					{
						std::cout << "\n\nНеккоректные данные\n\n";
					}
				}
				else
				{
					std::cout << "\n\nОшибка ввода\n\n";
				}
			}
			break;
		}
		else
		{
			std::cout << "\n\nОшибка ввода\n\n";
		}

	}
}

void ChangePrice()
{
	std::string idStr, newPriceStr;
	int id{}, newPrice{};
	bool exit = false;


	while (true)
	{
		std::cout << "Введите ID товара\t0 - Выход\nВвод: ";
		std::getline(std::cin, idStr, '\n');
		if (idStr == "0")
		{
			break;
		}

		else if (IsNumber(idStr))
		{
			id = std::stoi(idStr);
			std::cout << id - 1 << "\t" << std::left << std::setw(30) << nameArr[id - 1] << '\t' << countArr[id - 1] << 'n';
			while (true)
			{
				std::cout << "Введите новую цену: ";
				std::getline(std::cin, newPriceStr, '\n');
				if (IsNumber(newPriceStr))
				{
					newPriceStr = std::stoi(newPriceStr);
					if (newPrice >= 0 && newPrice <= 40000)
					{
						priceArr[id - 1] -= newPrice;
						std::cout << "\nНовая цена принята\n\n";
						break;
					}
					else
					{
						std::cout << "\n\nНеккоректные данные\n\n";
					}
				}
				else
				{
					std::cout << "\n\nОшибка ввода\n\n";
				}
			}
			break;
		}
		else
		{
			std::cout << "\n\nОшибка ввода\n\n";
		}

	}
}

void ChangeStaff()
{
	std::string choose;
	std::cout << "Изменение персонала магазина:\n\n";

	for (int i = 0; i < userCount; i++)
	{
		std::cout << i + 1 << " " << loginArr[i] << "   " << passwordArr[i] << "\n";
	}
	do
	{
		std::cout << "1 - добавить нового сотрудника\n2 - Изменить логин и пароль\n3 - Удалить текущего сотрудника\n0 - Выход\n\nВвод: ";
		std::getline(std::cin, choose, '\n');
	} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 51);

	if (choose == "1")
	{
		AddEmployee();
	}
	else if (choose == "2")
	{
		EmployeeEdit();
	}
	else if (choose == "3")
	{
		DeleteEmployee();
	}
	else if (choose == "0")
	{

	}
	else
	{
		std::cerr << "\nChangeStaffError\n\n";
	}
}

void AddEmployee()
{

	/*
		int userCount = 2;
		std::string* loginArr = new std::string[userCount]{ "admin", "user" };
		std::string* passwordArr = new std::string[userCount]{ "admin", "user" };
	*/

	std::string* tempLogin = new std::string[userCount];
	std::string* tempPass = new std::string[userCount];
	for (int i = 0; i < userCount; i++)
	{
		tempLogin[i] = loginArr[i];
		tempPass[i] = passwordArr[i];
	}


	//std::swap(loginArr, tempLogin);

	delete[]loginArr;
	delete[]passwordArr;
	userCount++;
	loginArr = new std::string[userCount];
	passwordArr = new std::string[userCount];
	for (int i = 0; i < userCount - 1; i++)
	{
		loginArr[i] = tempLogin[i];
		passwordArr[i] = tempPass[i];
	}
	std::string newLogin, newPass;
	std::cout << "Введите логин нового сотрудника: ";
	std::getline(std::cin, newLogin, '\n');
	std::cout << "Введите пароль нового сотрудника: ";
	std::getline(std::cin, newPass, '\n');

	loginArr[userCount - 1] = newLogin;
	passwordArr[userCount - 1] = newPass;
	delete[]tempLogin;
	delete[]tempPass;
}

bool IsNumber(std::string string)
{
	for (int i = 0; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
		{
			return false;
		}
	}
	return true;
}

void EmployeeEdit()
{
	std::string chooseId, newLogin, newPass;
	int empId{};
	while (true)
	{
		for (int i = 0; i < userCount; i++)
		{
			std::cout << i + 1 << "\t" << std::left << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr[i] << "\n";
		}
		std::cout << "Выберите ID пользователя\t0 - Выход\n Ввод: ";
		std::getline(std::cin, chooseId, '\n');
		if (chooseId == "0")
		{
			break;
		}
		else if (IsNumber(chooseId))
		{
			empId = std::stoi(chooseId);
			for (int i = 0; i < userCount; i++)
			{
				if (i == empId - 1)
				{
					std::cout << "Введите новый логин: ";
					std::getline(std::cin, newLogin, '\n');
					std::cout << "Введите пароль : ";
					std::getline(std::cin, newPass, '\n');

					loginArr[i] = newLogin;
					passwordArr[i] = newPass;
					break;
				}
			}
		}
		else
		{
			std::cout << "\n\nОшибка ввода\n\n";
		}
	}

}

void DeleteEmployee()
{

	std::string chooseId;
	int empId{};
	while (true)
	{
		std::cout << "Введите ID сотрудника для удаления\t0 - Выход\nВвод: ";
		std::getline(std::cin, chooseId, '\n');
		if (chooseId == "0")
		{
			break;
		}
		else if (IsNumber(chooseId))
		{
			empId = std::stoi(chooseId);
			std::string* tempLogin = new std::string[userCount];
			std::string* tempPass = new std::string[userCount];
			for (int i = 0; i < userCount; i++)
			{
				tempLogin[i] = loginArr[i];
				tempPass[i] = passwordArr[i];
			}


			delete[]loginArr;
			delete[]passwordArr;
			userCount--;
			loginArr = new std::string[userCount];
			passwordArr = new std::string[userCount];
			for (int i = 0, j = 0; i < userCount, j < userCount; i++, j++)
			{
				if (i == empId - 1)
				{
					i++;
					loginArr[j] = tempLogin[i];
					passwordArr[j] = tempPass[i];
				}
				else
				{
					loginArr[j] = tempLogin[i];
					passwordArr[j] = tempPass[i];
				}
			}
			break;
		}
		else
		{
			std::cout << "\n\nОшибка\n\n";
		}
	}

	std::string* tempLogin = new std::string[userCount];
	std::string* tempPass = new std::string[userCount];
	for (int i = 0; i < userCount; i++)
	{
		tempLogin[i] = loginArr[i];
		tempPass[i] = passwordArr[i];
	}


	delete[]loginArr;
	delete[]passwordArr;
	userCount--;
	std::string* templogin = new std::string[userCount];
	std::string* temppass = new std::string[userCount];
}

void ChangeStorage()
{


}

template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

template<typename ArrType>
void PrintArr(ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << dynamicArr[i] << " ";
	}
	std::cout << "\n";
}