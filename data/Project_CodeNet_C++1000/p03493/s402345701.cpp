#include <iostream>

int main(){
  int input;
  int count = 0;
  std::cin >> input;
  if (input%2!=0){
    count++;
  }
  if (input/10%2!=0){
    count++;
  }
  if (input/100!= 0){
    count++;
  }
  std::cout << count << std::endl;
  return 0;
}