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
constexpr int MAX = 100010;

int main(){
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    int cnt[n+10][n+10];
    rep(i, n+10)rep(j, n+10) cnt[i][j] = 0;
    rep(i, m){
        int L, R;
        scanf("%d%d", &L, &R);
        ++cnt[L][R];
    }
    rep(i, n+10)rep(j, n+9) cnt[i][j+1] += cnt[i][j];
    rep(j, n+10)rep(i, n+9) cnt[i+1][j] += cnt[i][j];

    rep(_, q){
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", cnt[b][b]-cnt[a-1][b]-cnt[b][a-1]+cnt[a-1][a-1]);
    }
}