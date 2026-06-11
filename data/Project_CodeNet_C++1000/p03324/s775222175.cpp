#include <iostream>

int main(){
   int D, N;
   std::cin >> D >> N;
   if (D == 0){
      if (N!=100){
         std::cout << N << std::endl;
      } else{
         std::cout << 101 << std::endl;
      }
   } else if (D == 1){
      if (N!=100){
         std::cout << 100*N << std::endl;
      } else{
         std::cout << 10100 << std::endl;
      }
   } else if (D == 2){
      if (N!=100){
         std::cout << 10000*N << std::endl;
      } else{
         std::cout << 1010000 << std::endl;
      }
   }
}

