#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i = 0; i <x; i++)
typedef long long ll;

const ll INF = 1LL<<60;

int main(){
    int H,W;
    cin >> H >> W;
    int dp[10][10];
    int A[H][W];

    rep(i,10)rep(j,10){
      cin >> dp[i][j];
    }

    rep(i,H)rep(j,W){
      cin >> A[i][j];
    }

    rep(k,10)rep(i,10)rep(j,10){
      dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
    }

    ll ans = 0;
    rep(i,H) rep(j,W){
      ans += dp[A[i][j]][1];
    }
    cout << ans << endl;
}
