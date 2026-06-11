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

int gcd(int a, int b) {
    if(b > a) return gcd(b , a);
    else if (b == 0) return a;
    else return gcd(b, a % b);
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int X, Y;
    cin >> X >> Y;
    if(X % Y == 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << X << endl;



    return 0;
}
