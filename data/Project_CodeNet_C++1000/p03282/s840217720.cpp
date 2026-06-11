#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
ll INF=1e18+5;
//cout << std::fixed << std::setprecision(15) << y << endl;

int main(){
  string S; ll K;
  cin >> S >> K;
  
  ll ans = 0;
  ll cnt = 0;
  rep(i,0,S.size()){
    ll p = S[i] - '0';
    if(p == 1) cnt++;
    else{ans = p; break;}
  }
  if(K > cnt)  cout << ans << endl;
  else cout << 1 << endl;
  return 0;
}