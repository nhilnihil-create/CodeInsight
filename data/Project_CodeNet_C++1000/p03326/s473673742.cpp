//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<ll>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n, m;
    cin >> n >> m;
    vi x(n), y(n), z(n);
    rep(i, n) {
        cin >> x[i] >> y[i] >> z[i];
    }

    vi dp;
    int kirei[2] = {1, -1};
    int oisisa[2] = {1, -1};
    int ninkido[2] = {1, -1};
    ll ans = -LINF;
    rep(i, 2) {
        rep(j, 2) {
            rep(k, 2) {
                dp.assign(m+1, -LINF);
                dp[0] = 0;
                rep(q, n) {
                    for(int l = m; l>0; --l) {
                        if(dp[l-1] == -LINF) continue;
                        dp[l] = max(dp[l], dp[l-1] + x[q]*kirei[i] + y[q]*oisisa[j] + z[q]*ninkido[k]); 
                    }
                }
                ans = max(ans, dp[m]);
            }
        }
    }

    cout << ans << endl;
}