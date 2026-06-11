#include<iostream>

int main(){
  
  int a,b,c;
  std::cin>>a>>b;
  c=a*b;
  if(c%2==0){
	std::cout<<"Even";
  }else{
    std::cout<<"Odd";
  }
  return 0; 
  
  
}