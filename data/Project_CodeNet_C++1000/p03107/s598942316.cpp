#include <iostream>
#include <string>

int main(){
   std::string S;
   std::cin >> S;
   int nzero = 0;
   for (size_t i=0; i<S.size(); i++){
      if (S.at(i) == '0'){
         nzero++;
      }
   }
   int none = S.size() - nzero;
   std::cout << 2 * std::min(nzero, none) << std::endl;

}

