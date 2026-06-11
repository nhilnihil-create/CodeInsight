#include "bits/stdc++.h"
using namespace std;
const int maxn = 333;
string u, v;
int dp[maxn][maxn][maxn];
int solve(int l, int r, int k){
    if(l > r) return 0;
    if(l == r) return 1;
    if(dp[l][r][k] != -1) return dp[l][r][k];
    int ans = 0;
    if(u[l] == u[r]) ans = max(ans, 2 + solve(l + 1, r - 1, k));
    ans = max(ans, solve(l+1, r, k));
    ans = max(ans, solve(l, r-1, k));
    if(k) ans = max(ans, 2 + solve(l + 1, r - 1, k - 1));
    return dp[l][r][k] = ans;
}
int main(){
    string c;
    cin >> c;
    int k;
    cin >> k;
    u = c;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, c.size() - 1, k) << endl;
    return 0;
}
