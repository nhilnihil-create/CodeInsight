#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod = 1'000'000'007;
const int INF = 1e9;

vvi dp(100010, vi(3, -1));
vvi a(100010, vi(3));

int rec(int n, int k){
    if (dp[n][k] != -1) return dp[n][k];
    if (n == 0) return dp[0][k] = 0;
    int res = 0;
    rep(i,3){
        if (k == i) continue;
        res = max(res, rec(n-1, i) + a[n][i]);
    }
    return dp[n][k] = res;
}

int main(){
    int n;
    cin >> n;
    REP(i,1,n+1)rep(j,3) cin >> a[i][j];
    int ans = 0;
    rep(i,3){
        ans = max(ans,rec(n, i));
    }
    cout << ans << endl;
    return 0;
}
