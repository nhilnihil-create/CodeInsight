#include <iostream>
#include <vector>

int main(){
   int N;
   std::cin >> N;
   std::vector<std::vector<int>> A(2, std::vector<int> (N));
   for (int i=0; i<2; i++){
      for (int j=0; j<N; j++){
         std::cin >> A.at(i).at(j);
      }
   }
   int max = 0;
   for (int i=0; i<N; i++){
      int sum0 = 0;
      int sum1 = 0;
      for (int j=i; j<N; j++){
         sum1 = sum1 + A.at(1).at(j);
      }
      for (int j=0; j<=i; j++){
         sum0 = sum0 + A.at(0).at(j);
      }
      if (sum0 + sum1 > max){
         max = sum0 + sum1;
      }
   }
   std::cout << max << std::endl;

}

