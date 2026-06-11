#include<iostream>
#include<string>
int main(){
  std::string X,Y;
  std::cin >> X >> Y;
  if(X[0] == Y[2] && X[1] == Y[1] && X[2] == Y[0]) std::cout<<"YES";
  else std::cout<<"NO";
}