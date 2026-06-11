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
constexpr int MAX = 10010;

int n;
vector<int> G[MAX];
int ans[MAX], c[MAX];
pii E[MAX];

int main(){
    scanf("%d", &n);
    rep(i, n-1){
        scanf("%d%d", &E[i].fi, &E[i].se);
        --E[i].fi; --E[i].se;
    }
    rep(i, n) scanf("%d", &c[i]);
    sort(c, c+n, greater<>());
    memset(ans, 0, sizeof(ans));
    ans[0] = c[0];
    int sum = 0;
    rep(k, n-1){
        rep(i, n-1)if((ans[E[i].fi] != 0) ^ (ans[E[i].se] != 0)){
            if(ans[E[i].fi]) ans[E[i].se] = c[k+1];
            else ans[E[i].fi] = c[k+1];
            sum += c[k+1];
            break;
        }
    }
    printf("%d\n", sum);
    rep(i, n) printf("%d ", ans[i]);
}