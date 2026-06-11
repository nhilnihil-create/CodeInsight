#include <iostream>
#include <vector>

int main(){
   int N, M, C;
   std::cin >> N >> M >> C;
   std::vector<int> B(M);
   for (int j=0; j<M; j++){
      std::cin >> B.at(j);
   }
   std::vector<std::vector<int>> A(N, std::vector<int> (M));
   for (int i=0; i<N; i++){
      for (int j=0; j<M; j++){
         std::cin >> A.at(i).at(j);
      }
   }
   int cnt=0;
   for (int i=0; i<N; i++){
      int temp = 0;
      for (int j=0; j<M; j++){
         temp = temp + A.at(i).at(j) * B.at(j);
      }
      temp = temp + C;
      if (temp > 0){
         cnt++;
      }
   }
   std::cout << cnt << std::endl;

}

