#include<iostream>
#include<string>
int main(){
  std::string str;
  std::cin>>str;
  int i;
  i=str.size();
  if(str[0]=='k'&&str[1]=='e'&&str[2]=='y'&&str[3]=='e'&&str[4]=='n'&&str[5]=='c'&&str[6]=='e'){
    std::cout<<"YES"<<std::endl;
  }else if(str[0]=='k'&&str[1]=='e'&&str[2]=='y'&&str[3]=='e'&&str[4]=='n'&&str[5]=='c'&&str[i-1]=='e'){
    std::cout<<"YES"<<std::endl;
  }else if(str[0]=='k'&&str[1]=='e'&&str[2]=='y'&&str[3]=='e'&&str[4]=='n'&&str[i-2]=='c'&&str[i-1]=='e'){
    std::cout<<"YES"<<std::endl;
  }else if(str[0]=='k'&&str[1]=='e'&&str[2]=='y'&&str[3]=='e'&&str[i-3]=='n'&&str[i-2]=='c'&&str[i-1]=='e'){
    std::cout<<"YES"<<std::endl;
  }else if(str[0]=='k'&&str[1]=='e'&&str[2]=='y'&&str[i-4]=='e'&&str[i-3]=='n'&&str[i-2]=='c'&&str[i-1]=='e'){
    std::cout<<"YES"<<std::endl;
  }else if(str[0]=='k'&&str[1]=='e'&&str[i-5]=='y'&&str[i-4]=='e'&&str[i-3]=='n'&&str[i-2]=='c'&&str[i-1]=='e'){
    std::cout<<"YES"<<std::endl;
  }else if(str[0]=='k'&&str[i-6]=='e'&&str[i-5]=='y'&&str[i-4]=='e'&&str[i-3]=='n'&&str[i-2]=='c'&&str[i-1]=='e'){
    std::cout<<"YES"<<std::endl;
  }else if(str[i-7]=='k'&&str[i-6]=='e'&&str[i-5]=='y'&&str[i-4]=='e'&&str[i-3]=='n'&&str[i-2]=='c'&&str[i-1]=='e'){
    std::cout<<"YES"<<std::endl;
  }else std::cout<<"NO"<<std::endl;
  return 0;
}