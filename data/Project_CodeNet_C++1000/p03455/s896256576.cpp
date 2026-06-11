#include<iostream>
 
int main()
{
	int X,Y;
	std::cin >> X >> Y;
	if((X*Y % 2) == 0)
	{
		std::cout << "Even" << std::endl;
	}else{
      std::cout << "Odd" << std::endl;
    }
}