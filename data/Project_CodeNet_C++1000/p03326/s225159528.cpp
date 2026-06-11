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
#define INF2 1000000000000000000
#define int long long

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int x[1010], y[1010], z[1010];
    rep(i, N) cin >> x[i] >> y[i] >> z[i];
    int ans = -INF2;
    rep(bit, 8) {
        vector<int> v;
        int sum = 0;
        rep(j, N) {
            int cost = 0;
            if (bit & (1 << 0)) cost += x[j];
            else cost -= x[j];
            if (bit & (1 << 1)) cost += y[j];
            else cost -= y[j];
            if (bit & (1 << 2)) cost += z[j];
            else cost -= z[j];
            v.push_back(cost);
        }
        sort(v.begin(), v.end(), greater<int>());
        rep(i, M) sum += v[i];
        ans = max(ans, sum);
    }
    cout << ans << endl;

    return 0;
}
