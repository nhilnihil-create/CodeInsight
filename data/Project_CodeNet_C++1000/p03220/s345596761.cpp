#include <iostream>
#include <vector>
#include <algorithm>

int main(){
   int N;
   std::cin >> N;
   int T;
   double A;
   std::cin >> T >> A;
   std::vector<int> H(N);
   for (int i=0; i<N; i++){
      std::cin >> H.at(i);
   }
   double min;
   int minN;
   for (int i=0; i<N; i++){
      double temp = T - H.at(i) * 0.006;
      if (temp > A)
         temp = temp - A;
      else
         temp = A - temp;
      std::cerr << temp << std::endl;
      if (i == 0){
         min = temp;
         minN = i;
      } else{
         if (temp < min){
            min = temp;
            minN = i;
         }
      }
   }
   std::cout << minN+1 << std::endl;
}

