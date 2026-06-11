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
typedef pair<int, lint> pil;
typedef pair<lint, int> pli;
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

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int X[n+1];
    X[0] = 0;
    rep(i, n) X[i+1] = X[i] ^ (1 << (s[i]-'a'));

    int dp[n+1];
    fill(dp, dp+n+1, MAX);
    dp[0] = 0;
    map<int, int> mp;
    mp[0] = 0;
    For(i, 1, n+1){
        if(mp.find(X[i]) != mp.end()) dp[i] = mp[X[i]] + 1;
        rep(j, 26){
            int t = X[i] ^ 1<<j;
            if(mp.find(t) != mp.end()) chmin(dp[i], mp[t] + 1);
        }
        if(mp.find(X[i]) == mp.end()) mp[X[i]] = dp[i];
        else chmin(mp[X[i]], dp[i]);
    }
    printf("%d\n", dp[n]);
}