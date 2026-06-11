#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
ll INF=1e18+5;

int main(){
  ll N;
  cin >> N;
  VL a(5);
  rep(i,0,5) cin >> a[i];
  VL t(5);

  t[0] = (N+a[0]-1)/a[0];
  ll ans = t[0];
  ll mov = INF;
  // t[i] i個目の交通機関が全員送り届け終わるまでの時刻（0-何分後か）
  rep(i,1,5){
    mov = min(mov, min(a[i], a[i-1]));
    t[i] = (N+mov-1)/mov + i;
  }
  cout << t[4] << endl;
  return 0;
}