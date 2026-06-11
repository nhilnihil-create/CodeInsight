#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (ll i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 62;
typedef pair<ll, ll> P;
int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> x(N), y(N), xt(N), yt(N);

    rep(i, N) {
        cin >> x[i] >> y[i];
        xt[i] = x[i];
        yt[i] = y[i];

    }

    sort(all(xt));
    sort(all(yt));

    ll ans = 1LL * (xt[N - 1] - xt[0]) * (yt[N - 1] - yt[0]);

    rep(xl, N) {
        repd(xr, xl + 1, N) {
            rep(yl, N) {
                repd(yr, yl + 1, N) {
                    int cnt = 0;
                    rep(i, N) {
                        if (x[i] >= xt[xl] && x[i] <= xt[xr] && y[i] >= yt[yl] && y[i] <= yt[yr]) cnt++;
                    }
                    if (cnt >= K) ans = min(ans, 1LL * (xt[xr] - xt[xl]) * (yt[yr] - yt[yl]));
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}