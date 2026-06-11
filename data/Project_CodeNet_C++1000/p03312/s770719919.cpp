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

int sum[200010];

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int A[200010];
    rep(i, N) cin >> A[i];
    rep(i, N) sum[i + 1] += sum[i] + A[i];
    int ans = INF2;
    REP(i, 2, N - 2) {
        int L = sum[i];
        int R = sum[N] - sum[i];
        auto itr1 = upper_bound(sum, sum + i, L/2);
        auto itr2 = upper_bound(sum + i, sum + N, L + R/2);
        --itr1; --itr2;
        rep(s, 2) {
            rep(t, 2) {
                //cout << *(itr1 + s) << " " << L - *(itr1 + s) << " " << *(itr2 + t) - L << " " << R - (*(itr2 + t) - L) << endl;
                int X1 = max({*(itr1 + s), L - *(itr1 + s), *(itr2 + t) - L, R - (*(itr2 + t) - L)});
                int X2 = min({*(itr1 + s), L - *(itr1 + s), *(itr2 + t) - L, R - (*(itr2 + t) - L)});
                ans = min(ans, X1 - X2);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
// 3 5 | 2 6