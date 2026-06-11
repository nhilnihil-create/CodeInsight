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


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int A[200010];
    rep(i, N) cin >> A[i];
    if (A[0] != 0) {cout << -1 << endl; return 0;}
    rep(i, N - 1) {
        if (A[i + 1] - A[i] >= 2) {
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = 0;
    rep(i, N - 1) {
        if (A[i] < A[i + 1]) ans++;
        else if (A[i] >= A[i + 1]) ans += A[i + 1];
    }
    cout << ans << endl;



    return 0;
}
// 0 1 2 3 3
// 0   1 2 3
//   1 2 3

// 0 1 2 1
// 0 0 0 1
//