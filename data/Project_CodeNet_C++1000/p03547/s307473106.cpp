#include<iostream>
int main(){
  char X,Y;
  std::cin >> X >> Y;
  if(X < Y) std::cout<<"<";
  else if(X > Y) std::cout<<">";
  else std::cout<<"=";
}