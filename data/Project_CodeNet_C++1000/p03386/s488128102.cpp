#include <iostream>

int main(){
   int A, B, K;
   std::cin >> A >> B >> K;
   int btm_max = A+K-1;
   int top_min = B-K+1;
   if ((K >= B) || (top_min <= btm_max)){
      for (int i=A; i<=B; i++){
         std::cout << i << std::endl;
      }
   }else {
      for (int i=A; i<=btm_max; i++){
         std::cout << i << std::endl;
      }
      for (int i=top_min; i<=B; i++){
         std::cout << i << std::endl;
      }
   }

}

