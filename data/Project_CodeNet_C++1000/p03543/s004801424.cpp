#include<iostream>
#include<string>
int main(){
  std::string N;
  std::cin >> N;
 
  std::cout << ((N[1] == N[2] && (N[1] == N[3] || N[1] == N[0]))? "Yes" : "No");
}