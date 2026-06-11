#include <iostream>
#include <string>

int main(){
   std::string S, T;
   std::cin >> S >> T;
   int N = S.size();
   bool flag = false;
   for (int i=0; i<N; i++){
      if (S != T){
         S = S.at(N-1) + S;
         S.pop_back();
      } else{
         flag = true;
      }
   }
   if (flag)
      std::cout << "Yes" << std::endl;
   else
      std::cout << "No" << std::endl;
}

