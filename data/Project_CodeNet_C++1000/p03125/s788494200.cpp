#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

int main(){
  int a,b;
  std::cin >> a >> b;
  if(b%a==0){
    std::cout << a+b;
  }else{
    std::cout << b-a;
  }
  return 0;
}