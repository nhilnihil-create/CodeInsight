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
#define int long long int

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    rep(i, Q) {
        int A, B;
        cin >> A >> B;

        int C = sqrt(A * B);
        int ans = 2 * C - 1;
        if (C * C == A * B && A != B) ans--;
        if (C * (C + 1) >= A * B) ans--;
        cout << ans << endl;
    }

    return 0;
}
