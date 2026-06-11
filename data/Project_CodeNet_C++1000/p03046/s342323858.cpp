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
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod*mod;
constexpr int MAX = 100010;

int main(){
    int m, K;
    scanf("%d%d", &m, &K);
    if(m==0) puts(K==0 ? "0 0" : "-1");
    else if(m==1) puts(K==0 ? "0 0 1 1" : "-1");
    else if(K >= 1<<m) puts("-1");
    else{
        rep(i, 1<<m)if(i!=K) printf("%d ", i);
        printf("%d ", K);
        rrep(i, 1<<m)if(i!=K) printf("%d ", i);
        printf("%d\n", K);
    }
}