#include <iostream>                                                                                                          

int main(){
   std::string S;
   std::cin >> S;

   const int N = S.size();
   int K = N;
   for(int l=(N-1)/2, r=N/2; l>=0; --l, ++r){
      if(S[l]!=S[N/2] || S[r]!=S[N/2]){
         std::cout << r << std::endl;
         return 0;
      }   
   }   

   std::cout << N << std::endl;
   
   return 0;
}