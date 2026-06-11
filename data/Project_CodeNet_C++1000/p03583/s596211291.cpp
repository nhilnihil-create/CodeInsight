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
            if((4*h*n - N*(n + h)) <= 0) continue;
            if(N * h * n % (4*h*n - N*(n + h)) != 0) continue;
            int w = N*h*n/(4*h*n - N*(n + h));
            if(w <= 0) continue;
            cout << h << " " << n << " " << w << endl;
            return 0;
        }
    }


    return 0;
}
// 4/N = 1/h + 1/n + 1/w
// 4hnw/N = (nw + hw + hn)
// 4hnw = N(nw + hw + hn)
// 4hnw - Nw(n + h) = Nhn
// w(4hn - N(n + h)) = Nhn