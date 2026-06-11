#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int d, g;
    cin >> d >> g;
    vector<int> p(d) , c(d);
    rep(i, d) cin >> p[i] >> c[i];

    int ans = INF;
    rep(s, 1 << d) {
        int score = 0;
        int tot = 0;
        vector<bool> check(d, true);
        rep(i, d) {
            if(s >> i & 1) {
                score += c[i] + p[i] * 100 * (i + 1);
                tot += p[i];
                check[i] = false;
            }
        }
        if(score < g) {
            for(int i = d - 1; i >= 0; i--) {
                if(check[i]) {
                    if(score + (p[i] - 1) * (i + 1) * 100 < g) break;
                    while(score < g) {
                        score += 100 * (i + 1);
                        tot++;
                    }
                    break;
                }
            }
        }
        if(score >= g) ans = min(ans, tot);
    }

    cout << ans << endl;
    return 0;
}