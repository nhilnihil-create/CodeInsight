#include <iostream>
#include <string>

int main(){
   std::string N;
   std::cin >> N;
   int keta = N.size();
   int M = N.at(0) -'0';
   int L = N.at(N.size()-1) -'0';
   //std::cerr << M << std::endl;
   if (keta == 1){
      std::cout << M << std::endl;
   } else if (L == 9){
      std::cout << (keta-1)*9+M << std::endl;
   } else{
      std::cout << (keta-1)*9+(M-1) << std::endl;
   }

}

