#include <stdio.h>
#include <iostream>

int main(void){
  int a, b, c;
  std::cin >> a >> b >> c;
  
  int d = a * b; 
  
  std::cout << ((d <= c) ? d : c) << std::endl;
  
  return 0;
}