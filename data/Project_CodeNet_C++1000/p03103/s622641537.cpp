#include <iostream>
#include <vector>
#include <algorithm>

int main(){
   int N, M;
   std::cin >> N >> M;
   std::vector<std::pair<long long int, long long int>> A;
   for (int i=0; i<N; i++){
      long long int price, zaiko;
      std::cin >> price >> zaiko;
      A.push_back({price, zaiko});
   }
   std::sort(A.begin(), A.end());
   long long int sum = 0;
   for (int i=0; i<N; i++){
      std::cerr << A.at(i).first << " " << A.at(i).second << std::endl;
      if(A.at(i).second <= M){
         sum = sum + A.at(i).first * A.at(i).second;
         std::cerr << A.at(i).first * A.at(i).second << std::endl;
         M = M - A.at(i).second;
      } else{
         sum = sum + A.at(i).first * M;
         break;
      }
   }
   std::cout << sum << std::endl;

}

