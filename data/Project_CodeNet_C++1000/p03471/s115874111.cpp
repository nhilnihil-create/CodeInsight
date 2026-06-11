#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,Y; cin >> N >>Y;
  for(int x = 0; x <= N; x++){
    for(int y = 0; y <= N - x; y++){
      int z = N -x -y;
      if(10000*x +5000*y+1000*z == Y){
        printf("%d %d %d\n",x,y,z);
        return 0;
      }
    }
  }
  printf("-1 -1 -1");
}