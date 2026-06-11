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
typedef pair<lint, lint> pll;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}
template<class T> T div_floor(const T a, const T b){return a>=0 ? a/b : (a+1)/b-1;}
template<class T> T div_ceil(const T a, const T b){return a>=0 ? (a-1)/b+1 : a/b;}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod*mod;
constexpr int MAX = 100010;

int main(){
    int a[4];
    rep(i, 4) scanf("%d", &a[i]);
    sort(a, a+4);
    int b[4] = {1, 4, 7, 9};
    rep(i, 4){
        if(a[i] != b[i]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}