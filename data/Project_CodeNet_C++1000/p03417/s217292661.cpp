#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  ll x,y;
  cin >> x >> y;
  // 幅が2以上の時
  // 内: 9回 裏 
  // 辺: 6回
  // 角: 4回
  
  // 幅が1の時
  // 辺: 3回
  // 角: 2回 裏
  
  // 1x1の時: 裏 
  
  ll ans = 0;
  if(x == 1 && y == 1){
    ans = 1;
  }
  if(x == 1 && y > 1){
    ans = y-2;
  }
  if(x > 1 && y == 1){
    ans = x-2;
  }
  if(x > 1 && y > 1){
    ans = (x-2)*(y-2);
  }
  
  cout << ans << endl;


}
