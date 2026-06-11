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
typedef pair<pii, lint> ppl;
typedef pair<lint, lint> pll;
typedef complex<double> xy_t;
typedef vector<lint> poly;

const lint mod = 1e9 + 7;

int main(){
    int n;
    scanf("%d", &n);
    ppl p[n];
    rep(i, n){
        int w, s;
        lint v;
        scanf("%d%d%lld", &w, &s, &v);
        p[i] = make_pair(make_pair(w, s), v);
    }
    sort(p, p+n, [](const ppl &a, const ppl &b){return a.fi.fi+a.fi.se < b.fi.fi+b.fi.se;});

    lint dp[2][20010];
    rep(i, 2)rep(j, 20010) dp[i][j] = -1;
    dp[0][0] = 0;
    rep(i, n){
        rep(j, 20010)if(dp[0][j] >= 0){
            dp[1][j] = max(dp[1][j], dp[0][j]);
            if(p[i].fi.se >= j && j+p[i].fi.fi < 20010){
                dp[1][j+p[i].fi.fi] = max(dp[1][j+p[i].fi.fi], dp[0][j] + p[i].se);
            }
        }
        rep(j, 20010){
            swap(dp[0][j], dp[1][j]);
            dp[1][j] = -1;
        }
    }

    lint ans = 0;
    rep(j, 20010) ans = max(ans, dp[0][j]);
    printf("%lld\n", ans);
}