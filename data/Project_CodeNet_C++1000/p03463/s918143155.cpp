#include<iostream>
int main(){
  int a,b,N;
  std::cin>>N>>a>>b;
  if((b-a+1)%2==0){
    std::cout<<"Borys"<<std::endl;
  }else
    std::cout<<"Alice"<<std::endl;
  return 0;
}

