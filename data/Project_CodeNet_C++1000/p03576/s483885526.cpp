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
#define INF2 5000000000000000000
#define int long long

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int x[51], y[51];
    rep(i, N) cin >> x[i] >> y[i];
    int ans = INF2;
    rep(i, N) {
        rep(j, N) {
            if (x[i] > x[j]) continue;
            rep(k, N) {
                if(x[j] > x[k]) continue;
                rep(s, N) {
                    if(x[k] > x[s]) continue;
                    int L = min({x[i], x[j], x[k], x[s]});
                    int R = max({x[i], x[j], x[k], x[s]});
                    int U = min({y[i], y[j], y[k], y[s]});
                    int D = max({y[i], y[j], y[k], y[s]});
                    int cnt = 0;
                    rep(t, N) {
                        if(L <= x[t] && x[t] <= R && U <= y[t] && y[t] <= D) cnt++;
                        if(cnt >= K || cnt + N - t < K) break;
                    }
                    if(cnt >= K) ans = min(ans, (R - L) * (D - U));
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
