#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
ll INF=1e18+5;
//cout << std::fixed << std::setprecision(15) << y << endl;

int main(){
  ll N; string S;
  cin >> N >> S;
  ll cnte = 0, cntw = 0;
  VL e(N,0); VL w(N,0);
  rep(i,0,N){
    if(S[i] == 'E') cnte++;
    e[i] = cnte;
  }
  rep(i,0,N){
    if(S[N-1-i] == 'W') cntw++;
    w[N-1-i] = cntw;
  }

  ll ans = INF;
  ll tmp;
  rep(i,0,N){
    tmp = (N-1) - (e[i]+w[i]-1);//自分を引く
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}