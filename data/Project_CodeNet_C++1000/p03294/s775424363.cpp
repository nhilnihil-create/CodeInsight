#include <iostream>
#include <vector>
#include <algorithm>

int main(){
   int N;
   std::cin >> N;
   std::vector<int> a(N);
   for (int i=0; i<N; i++){
      std::cin >> a.at(i);
   }
   long long int sum = 0;
   for (int i=0; i<N; i++){
      sum = sum + a.at(i)-1;
   }
   std::cout << sum << std::endl;
}

