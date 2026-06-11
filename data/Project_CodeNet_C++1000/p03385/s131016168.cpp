#include<string>
#include<iostream>

int main(){
  std::string str;
  std::cin>>str;
  if(str=="abc"||str=="acb"||str=="cab"||str=="bac"||str=="bca"||str=="cba")
    std::cout<<"Yes"<<std::endl;
  else std::cout<<"No"<<std::endl;
  return 0;
}