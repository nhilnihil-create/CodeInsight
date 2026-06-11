#include <bits/stdc++.h>
using namespace std;

int main(){
   int N, Y;
   cin >> N >> Y;
   bool flag = false;
   int x, y, z;
   for (int i=0; i<=2000; i++){
      if ((Y - 1000*N - 9000*i) % 4000 == 0){
         y = (Y - 1000*N - 9000*i) / 4000;
         x = i;
         z = N - x - y;
         if ((y >= 0) && (z >= 0)){
            flag = true;
            break;
         }
      }
   }
   if (flag){
      cout << x << " " << y << " " << z << std::endl;
   } else{
      cout << -1 << " " << -1 << " " << -1 << std::endl;
   }

}

