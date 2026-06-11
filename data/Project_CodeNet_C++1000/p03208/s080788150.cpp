#include <iostream>
#include <vector>
#include <algorithm>

int main(){
   int N, K;
   std::cin >> N >> K;
   std::vector<int> h(N);
   for (int i=0; i<N; i++){
      std::cin >> h.at(i);
   }
   std::sort(h.begin(), h.end());
   int min = 1000000000;
   for (int i=0; i<N-K+1; i++){
      int temp = h.at(i+K-1) - h.at(i);
      if (temp < min){
         min = temp;
      }
   }
   std::cout << min << std::endl;
}

