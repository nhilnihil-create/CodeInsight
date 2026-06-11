#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pil;
typedef complex<double> xy_t;

const lint mod = 1e9 + 7;

int main(){
    int n;
    scanf("%d", &n);
    int c[n];
    rep(i, n) scanf("%d", &c[i]);

    lint dpsum[200010], dp[n];
    rep(i, 200010) dpsum[i] = 0;
    rep(i, n) dp[i] = 0;
    dpsum[c[0]] = 1;
    rep(i, n){
        dp[i] = dpsum[c[i]];
        if(i < n-1 && c[i] != c[i+1]){
            (dpsum[c[i+1]] += dp[i]) %= mod;
        }
    }

    printf("%lld\n", dp[n-1]);
}