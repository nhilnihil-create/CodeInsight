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
    int N; cin >> N;
    REP(h, 1, 3500) {
        REP(n, 1, 3500) {
            if (4 * n * h % N != 0) continue;
            int t = 4 * n * h / N;
            if (t - n - h <= 0) continue;
            if (h * n % (t - n - h) != 0) continue;
            int w = (h * n)/(t - n - h);
            cout << h << " " << n << " " << w << endl;
            return 0;
        }
    }

    return 0;
}

// 4nhw/N - nw - hw = hn
// w(4nh/N - n - h) = hn
// w = hn/(4nH/N - n - h)