#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define repr1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
const double PI = acos(-1);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int n, k; cin >> n >> k;
    vector<pll> v(n);
    rep(i, n) cin >> v[i].first >> v[i].second;

    vector<ll> xs, ys;
    rep(i, n) {
        xs.push_back(v[i].first);
        ys.push_back(v[i].second);
    }

    sort(all(xs)); sort(all(ys));

    ll ans = (xs[n-1] - xs[0]) * (ys[n-1] - ys[0]);
    for (int yi = 0; yi < n; yi++) {
        for (int yj = yi+1; yj < n; yj++) {
            for (int xi = 0; xi < n; xi++) {
                for (int xj = xi+1; xj < n; xj++) {
                    int cnt = 0;
                    rep(i, n) {
                        ll x = v[i].first;
                        ll y = v[i].second;
                        if (xs[xi] <= x && x <= xs[xj] &&
                                ys[yi] <= y && y <= ys[yj]) {
                            cnt++;
                        }
                    }

                    if (cnt >= k) {
                        ll tmp = (xs[xj] - xs[xi]) * (ys[yj] - ys[yi]);
                        chmin(ans, tmp);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
