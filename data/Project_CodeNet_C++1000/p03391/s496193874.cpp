#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef complex<double> xy_t;
typedef vector<lint> poly;

const lint mod = 1e9 + 7;
const lint INF = mod * mod;

int main(){
    int n;
    scanf("%d", &n);
    lint bm = INF, sum = 0;
    rep(i, n){
        lint a, b;
        scanf("%lld%lld", &a, &b);
        if(a > b) bm = min(bm, b);
        sum += a;
    }
    printf("%lld\n", bm < INF ? sum-bm : 0);
}