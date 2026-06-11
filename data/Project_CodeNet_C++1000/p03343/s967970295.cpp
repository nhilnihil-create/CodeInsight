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

int main(){
    int n, K, q;
    scanf("%d%d%d", &n, &K, &q);
    int a[n];
    rep(i, n) scanf("%d", &a[i]);

    int ans = mod;
    rep(i, n){
        vector<int> u, v;
        int l = 0;
        while(l < n){
            if(a[l] < a[i]){
                ++l;
                continue;
            }
            int r = l;
            while(r < n && a[r] >= a[i]) ++r;
            For(j, l, r) u.push_back(a[j]);
            l = r;

            sort(u.begin(), u.end());
            rep(j, u.size()-K+1) v.push_back(u[j]);
            u.clear();
        }
        if(v.size() < q) continue;
        sort(v.begin(), v.end());
        chmin(ans, v[q-1] - a[i]);
    }
    printf("%d\n", ans);
}
