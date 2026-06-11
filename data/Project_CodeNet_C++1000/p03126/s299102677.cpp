#include <iostream>
#include <map>

int main(){
   int N, M;
   std::cin >> N >> M;
   std::map<int, int> mp;
   for (int i=0; i<N; i++){
      int k;
      std::cin >> k;
      for (int j=0; j<k; j++){
         int key;
         std::cin >> key;
         mp[key]++;
      }
   }
   int cnt = 0;
   for (auto x : mp){
      if (x.second == N){
         cnt++;
      }
   }
   std::cout << cnt << std::endl;
}

