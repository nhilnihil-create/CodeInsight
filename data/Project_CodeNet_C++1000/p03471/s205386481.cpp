#include <bits/stdc++.h>
using namespace std;

int main() {

  int N,Y;
  cin >> N >> Y;
  int x,y,z,ans=0,money;
  for(x=0;x<=N;x++){
      if(x*10000>Y){
          break;
      }
      for(y=0;y<=N-x;y++){
          z = N-x-y;
          money = 10000*x+5000*y+1000*z;
          if(money==Y){
              ans=1;
              cout << x << " " << y << " " << z << endl;
              break;
          }
      }
      if(ans == 1){
          break;
      }
  }
  if(ans == 0){
      cout << -1 << " " << -1 << " "<< -1 << endl;
  }

}