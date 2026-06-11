#include <iostream>
#include <vector>

int main(){
   int N, D, X;
   std::cin >> N >> D >> X;
   std::vector<int> A(N);
   for (int i=0; i<N; i++){
      std::cin >> A.at(i);
   }
   int cnt = 0;
   for (int i=0; i<N; i++){
      int j = 0;
      while (j*A.at(i) + 1 <= D){
         j++;
      }
      cnt = cnt + j;
   }
   std::cout << cnt+X << std::endl;
}

