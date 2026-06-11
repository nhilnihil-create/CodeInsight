#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rFor(i, a, b) for(int (i)=(int)(a)-1; (i)>=(int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
#define double long double
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
    int h, w, n;
    scanf("%d%d%d", &h, &w, &n);
    vector<int> v[w];
    rep(i, n){
        int x, y;
        scanf("%d%d", &x, &y);
        v[y-1].push_back(x-1);
    }
    rep(y, w) sort(v[y].begin(), v[y].end());
    int l = -1, r = h-1;
    int ans = h;
    rep(y, w){
        ++l;
        chmax(l, y);
        for(auto x: v[y])if(l <= x && x <= r){
            if(x == l) ++l;
            else chmin(r, x-1);
        }
        if(r < l) break;
        chmin(ans, r+1);
    }
    printf("%d\n", ans);
}