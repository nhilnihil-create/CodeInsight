#include <iostream>
#include <vector>

int main(){
   int N;
   std::cin >> N;
   struct T{
      int t;
      int x;
      int y;
   };
   std::vector<T> v(N);
   for (int i=0; i<N; i++){
      int t, x, y;
      std::cin >> t >> x >> y;
      v.at(i).t = t;
      v.at(i).x = x;
      v.at(i).y = y;
   }
   //for (auto x : v){
   //   std::cout << x.t << " " << x.x << " " << x.y << std::endl;
   //}
   int t = 0, x = 0, y = 0;
   bool flag = true;
   for (int i=0; i<N; i++){
      int abst = v.at(i).t - t; 
      int absr = abs(v.at(i).x - x) + abs(v.at(i).y - y);
      if (abst < absr){
         flag = false;
         break;
      } else if ((abst % 2 == 0) && (absr % 2 == 1)){
         flag = false;
         break;
      } else if ((abst % 2 == 1) && (absr % 2 == 0)){
         flag = false;
         break;
      } else{
         t = v.at(i).t;
         x = v.at(i).x;
         y = v.at(i).y;
      }
   }
   if (flag){
      std::cout << "Yes" << std::endl;
   } else{
      std::cout << "No" << std::endl;
   }

}

