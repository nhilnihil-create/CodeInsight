#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  int pre_x = 0;
  int pre_y = 0;
  int pre_t = 0;

  string ans = "Yes";

  rep(i,n){
    int t,x,y;
    cin >> t >> x >> y;

    //時刻と座標の和の偶奇が一致するか
    if(t%2!=(x+y)%2){
      ans = "No";
      continue;
    }

    //前の時刻から間に合う範囲内か
    if(t-pre_t<abs(x-pre_x)+abs(y-pre_y)){
      ans = "No";
      continue;
    }

    //前の時刻からちょうど到達できる場所か
    if((t-pre_t)%2!=(abs(x-pre_x)+abs(y-pre_y))%2){
      ans = "No";
      continue;
    }

    //更新
    pre_x = x;
    pre_y = y;
    pre_t = t;
  }

  cout << ans << endl;

  return 0;
}