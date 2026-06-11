#include <iostream>
#include <vector>
#include <algorithm>

int main(){
   int A, B, C;
   std::cin >> A >> B >> C;
   std::vector<int> v = {A, B, C};
   std::sort(v.begin(), v.end());
   A = v.at(0);
   B = v.at(1);
   C = v.at(2);
   int cnt = 0;
   while (!((A == B) && (B == C) && (A == C))){
      if (A == B){
         A = A + 1;
         B = B + 1;
         cnt++;
         if (A >= C){
            std::swap(A, C);
         }
      } else{
         A = A + 2;
         cnt++;
         if (A >= C){
            std::swap(A, C);
            std::swap(A, B);
         } else if ((A >= B) && (A < C)){
            std::swap(A, B);
         }
      }
   }
   std::cout << cnt << std::endl;
}

