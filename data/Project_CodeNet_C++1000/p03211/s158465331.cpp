#include <iostream>
#include <string>
#include <algorithm>

int main(){
   std::string S;
   std::cin >> S;
   size_t N = S.size();
   int min = 753;
   for (int i=0; i<=N-3; i++){
      std::string subS = S.substr(i, 3);
      int X = atoi(subS.c_str());
      int tmp = std::abs(X - 753);
      min = std::min(min, tmp);
   }
   std::cout << min << std::endl;

}

