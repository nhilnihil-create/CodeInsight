#include <iostream>

int main(){
  char s[3]={};
  for(int i=0;i<3;i++)
  	std::cin>>s[i];
  if(s[2]==0){
    std::cout<<s[0]<<s[1];
  }else
  for(int i=2;i>=0;--i){
  	std::cout<<s[i];
  }
  return 0;
}