#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <bitset>
#include <cmath>

int main(){
   int N;
   std::cin >> N;
   std::vector<int> V(N);
   std::vector<int> C(N);
   for (int i=0; i<N; i++){
      std::cin >> V.at(i);
   }
   for (int i=0; i<N; i++){
      std::cin >> C.at(i);
   }
   int max = 0;
   int nmax = std::pow(2, N);
   for (int i=0; i<nmax; i++){
      std::stringstream i_ss;
      i_ss << std::bitset<20>(i);
      std::string i_s = i_ss.str();
      if (i<10){
         std::cerr << i_s << std::endl;
      }
      int Y = 0, X = 0;
      for (int j=0; j<N; j++){
         if (i_s.at(19-j) == '1'){
            Y = Y + C.at(j);
            X = X + V.at(j);
            max = std::max(max, X-Y);
         }
      }
   }
   std::cout << max << std::endl;
}

