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
   int cnt = 0;
   for (int i=0; i<N; i++){
      if (a.at(i) % 2 == 0){
         int temp = a.at(i);
         while (temp % 2 == 0){
            temp = temp / 2;
            cnt++;
         }
         std::cerr << a.at(i) << " " << cnt << std::endl;
      }
   }
   std::cout << cnt << std::endl;
}

