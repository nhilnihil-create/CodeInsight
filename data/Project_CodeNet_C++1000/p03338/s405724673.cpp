#include <iostream>
#include <string>
#include <algorithm>

int main(){
   int N;
   std::cin >> N;
   std::string S;
   std::cin >> S;
   int max = 0;
   for (int i=1; i<N; i++){
      std::string X = S.substr(0, i);
      std::string Y = S.substr(i, N-i);
      std::sort(X.begin(), X.end());
      std::sort(Y.begin(), Y.end());
      //std::cerr << X << " " << Y << std::endl;
      X.erase(std::unique(X.begin(), X.end()), X.end());
      Y.erase(std::unique(Y.begin(), Y.end()), Y.end());
      //std::cerr << X << " " << Y << std::endl;
      int cnt = 0;
      for (auto x : X){
         if (std::any_of(Y.begin(), Y.end(), [=](auto y){return y == x;})){
            cnt++;
         }
      }
      max = std::max(max, cnt);
   }
   std::cout << max << std::endl;
}

