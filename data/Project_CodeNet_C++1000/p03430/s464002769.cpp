#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rFor(i, a, b) for(int (i)=(int)(a)-1; (i)>=(int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}
template<class T> T div_floor(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>=0 ? a/b : (a+1)/b-1;
}
template<class T> T div_ceil(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>0 ? (a-1)/b+1 : a/b;
}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod * mod;
constexpr int MAX = 200010;

string s;
int n, K, dp[310][310][310];

int dfs(int l, int r, int t){
    if(dp[l][r][t] >= 0) return dp[l][r][t];
    if(l == r) return dp[l][r][t] = 0;
    if(r-l == 1) return dp[l][r][t] = 1;
    int ret = max(dfs(l+1, r, t), dfs(l, r-1, t));
    if(s[l] == s[r-1]) chmax(ret, 2 + dfs(l+1, r-1, t));
    else if(t > 0) chmax(ret, 2 + dfs(l+1, r-1, t-1));
    return dp[l][r][t] = ret;
}

int main(){
    cin >> s >> K;
    int n = s.size();
    rep(i, n+1)rep(j, n+1)rep(k, K+1) dp[i][j][k] = -1;
    printf("%d\n", dfs(0, n, K));
}