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
    int A[100010], B[100010];
    int N; cin >> N;
    bool same = true;
    int sum = 0;
    int small = INF2;
    rep(i, N) {
        cin >> A[i] >> B[i];
        if (A[i] != B[i]) same = false;
        sum += A[i];
        if (A[i] - B[i] > 0) small = min(small, B[i]);
    }
    if(same) {cout << 0 << endl; return 0;}
    cout << sum - small << endl;

    return 0;
}
