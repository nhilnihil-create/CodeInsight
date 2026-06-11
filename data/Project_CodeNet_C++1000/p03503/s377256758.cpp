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
    int n;
    cin >> n;
    vvi f(n, vi(10));
    rep(i, n) {
        rep(j, 10) {
            cin >> f[i][j];
        }
    }
    vvi p(n, vi(11));
    rep(i, n) {
        rep(j, 11) {
            cin >> p[i][j];
        }
    }

    ll ans = -LINF;
    rep(i, 1024) {
        if(i == 0) continue;
        ll now=0;
        vi nnow(n);
        rep(j, n) {
            rep(k, 10) {
                if((i>>k)&1 && f[j][k]) {
                    nnow[j]++;
                }
            }
        }
        
        rep(j, n) {
            now += p[j][nnow[j]];
        }
        ans = max(ans, now);
    }

    cout << ans << endl;
}