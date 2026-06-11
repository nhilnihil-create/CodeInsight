#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 8000000000000000000
#define int long long

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int x[51], y[51];
    rep(i, N) {
        cin >> x[i] >> y[i];
    }
    int ans = INF2;
    rep(i, N) {
        rep(j, N) {
            rep(k, N) {
                rep(s, N) {
                    int x1 = min({x[i], x[j], x[k], x[s]});
                    int x2 = max({x[i], x[j], x[k], x[s]});
                    int y1 = min({y[i], y[j], y[k], y[s]});
                    int y2 = max({y[i], y[j], y[k], y[s]});
                    int cnt = 0;
                    rep(t, N) {
                        if (x1 <= x[t] && x[t] <= x2 && y1 <= y[t] && y[t] <= y2) cnt++;
                    }
                    if (cnt >= K) ans = min(ans, (x2 - x1) * (y2 - y1));
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
