#include <iostream>
int main(){
  int A,B,C;
  std::cin>>A>>B>>C;
      if (A==B){
       std::cout<<C;
      }
      if (A==C){
       std::cout<<B;
      }
      if (B==C){
        std::cout<<A;
      }
  }