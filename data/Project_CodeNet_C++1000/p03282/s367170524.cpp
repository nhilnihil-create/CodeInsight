#include <iostream>
#include <string>
#include <cmath>

int main(){
   std::string S;
   std::cin >> S;
   long long int K;
   std::cin >> K;
   bool flag = false;
   int index = 0;
   char val;
   for (int i=0; i<S.size(); i++){
      if (S.at(i) != '1'){
         if (i >= K){
            std::cout << 1 << std::endl;
         } else{
            std::cout << S.at(i) << std::endl;
         }
         flag = true;
         break;
      }
   }

   if (!flag)
      std::cout << 1 << std::endl;
}

