#include <iostream>
#include <vector>

int main(){
   int N;
   std::cin >> N;
   std::vector<int> h(N);
   for (int i=0; i<N; i++){
      std::cin >> h.at(i);
   }
   int cnt = 0;
   int i = 0;
   while (i<N){
      if (h.at(i) == 0){
         i++;
      } else{
         cnt++;
         for (int j=i; j<N; j++){
            if (h.at(j) == 0){
               break;
            } else{
               h.at(j)--;
            }
         }
      }
      //for (auto x : h){
      //   std::cerr << x;
      //}
      //std::cerr << std::endl;
   }
   std::cout << cnt << std::endl;
}

