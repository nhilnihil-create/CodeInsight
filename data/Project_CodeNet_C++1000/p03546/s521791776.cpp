#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int INF = 1e9;

int main(){
    int h,w;
    cin >> h >> w;
    int table[10][10];
    int box[h][w];
    rep(i,10)rep(j,10) cin >> table[i][j];
    rep(i,h)rep(j,w) cin >> box[i][j];

    int dp[10][10];
    rep(i,10) {
        dp[0][i] = INF;
        dp[1][i] = table[i][1];
    }
    for(int i = 1;i<=8;i++){
        rep(j,10){
            if(j==1) continue;
            dp[i+1][j] = dp[i][j];
            rep(k,10){
                if(k==j || k==1) continue;
                dp[i+1][j] = min(dp[i+1][j],dp[i][k]+table[j][k]);
            }
        }
    }
    int ans = 0;
    rep(i,h)rep(j,w){
        if(abs(box[i][j])!=1) ans += dp[9][box[i][j]];
    }

    cout << ans << endl;

}