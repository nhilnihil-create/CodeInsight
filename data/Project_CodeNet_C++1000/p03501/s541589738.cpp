#include <iostream>

int main(){
  int time , price , regular;
  std::cin >> time >> price >> regular;
  
  if(time * price < regular){
    std::cout << time * price << std::endl;
  }
  else{
    std::cout << regular << std::endl;
  }
}