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

int n, m;
vector<int> G[MAX];
int c[MAX];
lint cnt[2];

bool dfs(int v, int col){
    if(c[v] >= 0) return c[v] == col;
    c[v] = col;
    ++cnt[col];
    for(int nv: G[v]){
        if(!dfs(nv, col^1)) return false;
    }
    return true;
}

int main(){
    scanf("%d%d", &n, &m);
    rep(i, m){
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cnt[0] = cnt[1] = 0;
    fill(c, c+n, -1);
    if(dfs(0, 0)) printf("%lld\n", cnt[0]*cnt[1] - m);
    else printf("%lld\n", 1LL * n*(n-1)/2 - m);
}