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
constexpr int MAX = 200010;

int main(){
    int n, c;
    scanf("%d%d", &n, &c);
    lint d[c][c];
    int col[n][n];
    rep(i, c)rep(j, c) scanf("%lld", &d[i][j]);
    rep(i, n)rep(j, n){
        scanf("%d", &col[i][j]);
        --col[i][j];
    }

    lint sum[3][c];
    rep(i, 3)rep(j, c) sum[i][j] = 0;
    rep(i, n)rep(j, n)rep(k, c){
        sum[(i+j)%3][k] += d[col[i][j]][k];
    }
    lint ans = INF;
    rep(i, c)rep(j, c)rep(k, c)if(i!=j && j!=k && k!=i){
        chmin(ans, sum[0][i] + sum[1][j] + sum[2][k]);
    }
    printf("%lld\n", ans);
}