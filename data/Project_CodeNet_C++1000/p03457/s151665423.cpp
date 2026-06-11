#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,t,ansx,ansy;
  int x = 0,y = 0,i = 0,now = 0;
  bool judge = true;
  cin >> N;
  while(i != N){
    cin >> t >> ansx >> ansy;
    now = t - now;
    for(int j = 0; j < now; j++){
      if(ansx != x){
        x < ansx ? x++ : x--;
      } else {
        y <= ansy ? y++ : y--;
      }
    }

    if(x == ansx && y == ansy){
      now = t;
    } else {
      judge = false;
      break;
    }
    i++;
  }
    
  cout << (judge == true ? "Yes" : "No") << endl;
}