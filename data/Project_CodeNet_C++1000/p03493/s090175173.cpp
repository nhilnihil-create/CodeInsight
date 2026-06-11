#include <iostream>

int main()
{
  std::string input;
  std::cin >> input;
  
  int count = 0;
  for (char c : input)
  {
    if (c == '1') count++;
  }
  
  std::cout << count;
  
  return 0;
}