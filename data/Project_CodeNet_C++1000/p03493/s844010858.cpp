#include <iostream>

int main(void){
  char str[4];
  int i, count = 0;
  std::cin >> str;
  for(i = 0; i < 3; i++)
    if(str[i] == '1') count++;
  std::cout << count << std::endl;
  return 0;
}