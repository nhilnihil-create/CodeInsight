#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>
#include <list>

using namespace std;
typedef long long int ll;

#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define rrep(i,a) for(ll i=a-1;i>=0;i--)
#define COSTMAX A * N

ll llmin(ll a, ll b){
  return a < b ? a : b;
}

int main(){
  ll N, A, B;
  cin >> N >> A >> B;
  ll idx[N];
  rep(i, N){
    ll p;
    cin >> p;
    idx[p-1] = i;
  }

  ll dp[N][N+1];
  rep(i, N) rep(j, N+1) dp[i][j] = COSTMAX;
  if(idx[0] == 0){
    dp[0][0] = 0;
  } else{
    dp[0][0] = B;
    dp[0][idx[0]] = 0;
  }

  rep(a, N-1){
    rep(b, N+1){
      if(dp[a][b] == COSTMAX) continue;
      if(b <= idx[a+1]){
        dp[a+1][b] = llmin(dp[a+1][b], dp[a][b] + B);
        dp[a+1][idx[a+1]] = llmin(dp[a+1][idx[a+1]], dp[a][b]);
      }
      else{
        dp[a+1][b] = llmin(dp[a+1][b], dp[a][b] + A);
      }
    }
  }
  ll ans = llmin(A, B) * N;
  rep(i, N+1) ans = llmin(ans, dp[N-1][i]);
  cout << ans << endl;
  // rep(i, N){
  //   rep(j, N+1) cout << dp[i][j] << " ";
  //   cout << endl;
  // }
  return 0;
}
