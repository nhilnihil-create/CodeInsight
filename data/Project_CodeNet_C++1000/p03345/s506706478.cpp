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
    int A, B, C, K;
    cin >> A >> B >> C >> K;
    K++;
    cout << (A - B) * ((K % 2 - 1) * 2 + 1) << endl;


    return 0;
}
// A1 = B + C;
// B1 = C + A;
// C1 = A + B;
// A2 = B1 + C1 = C + A + A + B;
// B2 = C1 + A1 = A + B + B + C
// C2 = A1 + B1 = B + C + C + A;