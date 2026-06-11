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
constexpr int MAX = 100010;

int cmp(string s, string t){
    if(s.size() > t.size()) return 1;
    else if(s.size() < t.size()) return -1;
    else{
        rep(i, s.size()){
            if(s[i] < t[i]) return -1;
            else if(s[i] > t[i]) return 1;
        }
        return 0;
    }
}

int num[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int a[m];
    rep(i, m) scanf("%d", &a[i]);
    string dp[n+1];
    rep(i, n)if(i == 0 || !dp[i].empty()){
        rep(j, m){
            char c = '0' + a[j];
            if(i+num[a[j]] <= n && cmp(dp[i] + c, dp[i+num[a[j]]]) == 1){
                dp[i+num[a[j]]] = dp[i] + c;
            }
        }
    }
    cout << dp[n] << "\n";
}