#include<iostream>
int main(){
  int price=700;
  for(int i=0; i<3; i++){
    char ch=getchar();
    if(ch=='o') price += 100;
  }
  std::cout << price << std::endl;
}
