#include <iostream>

int main()
{
  int a, b;
  std::cin >> a >> b;
	
  int num = a;
  
  if ( a > b ) --num;
  
  std::cout << num << std::endl;
}