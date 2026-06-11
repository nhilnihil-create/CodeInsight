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
    int x[11];
    rep(i, N) cin >> x[i];
    int pattern = 1;
    rep(i, N) pattern *= 3; 
    int ans = 0;
    rep(tmp, pattern) {
        int bit = tmp;
        int y[11];
        rep(i, N) {
            y[i] = x[i] + bit % 3 - 1;
            bit /= 3;
        }
        bool ok = false;
        rep(i, N) if(y[i] % 2 == 0) ok = true;
        ans += ok;
        //rep(i, N) cout << y[i] << " ";
        //cout << ok  << endl;
    }
    cout << ans << endl;

    return 0;
}
