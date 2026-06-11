#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main(){
   int N;
   long long int x;
   std::cin >> N >> x;
   std::vector<long long int> a(N);
   for (int i=0; i<N; i++){
      std::cin >> a.at(i);
   }
   long long int sum = std::accumulate(a.begin(), a.end(), 0LL);
   std::sort(a.begin(), a.end());
   if (sum == x){
      std::cout << N << std::endl;
   } else if (sum < x){
      std::cout << N-1 << std::endl;
   } else{
      for (int i=0; i<N; i++){
         x = x - a.at(i);
         if (x == 0){
            std::cout << i+1 << std::endl;
            break;
         } else if (x < 0){
            std::cout << i << std::endl;
            break;
         }
      }
   }
}

