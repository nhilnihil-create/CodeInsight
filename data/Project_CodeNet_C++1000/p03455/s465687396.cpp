#include <iostream>

int main()
{
  int a, b;
  std::cin >> a >> b;
  
  int ans = a * b;
  
  std::cout << ((ans % 2) ? "Odd" : "Even");
  
  return 0;
}