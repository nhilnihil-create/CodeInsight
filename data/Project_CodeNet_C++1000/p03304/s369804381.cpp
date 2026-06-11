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
    int n, m, d;
    cin >> n >> m >> d;
    if (d == 0) {
        cout << fixed << setprecision(12) << (m - 1.0)/n << endl;
    } else {
        cout << fixed << setprecision(12) << (m - 1.0) * ((n - d) * 2)/(n * n)<< endl;
    }

    return 0;
}
// 1 1 :0
// 1 2 :1
// 1 3: 0
// 2 1 :1
// 2 2: 0
///2 3: 1