#include<iostream>
#include <string>
 
int main()
{
	std::string str;
  	int counter = 0;
	std::cin >> str;
	if(str[0] == '1') counter++;
  	if(str[1] == '1') counter++;
  	if(str[2] == '1') counter++;
  
  	std::cout << counter << std::endl;
}