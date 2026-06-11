#include <iostream>
#include <cmath>

int main(){
   int X;
   std::cin >> X;
   int max = 1;
   for (int i=1; i<=32; i++){
      for (int j=2; j<=9; j++){
         int tmp = std::pow(i, j);
         if (tmp <= X){
            max = std::max(max, tmp);
         }
      }
   }
   std::cout << max << std::endl;

}

