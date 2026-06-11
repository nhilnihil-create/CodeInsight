#include <iostream>
#include <string>

int main(){
   int A, B;
   std::cin >> A >> B;
   std::string S;
   std::cin >> S;
   bool flag = true;
   for (int i=0; i<A+B+1; ++i){
      if (i == A){
         if (S.at(i) != '-'){
            flag = false;
         }
      }else {
         if (S.at(i) == '-'){
            flag = false;
         }
      }
   }
   if (flag)
      std::cout << "Yes" << std::endl;
   else
      std::cout << "No" << std::endl;

}

