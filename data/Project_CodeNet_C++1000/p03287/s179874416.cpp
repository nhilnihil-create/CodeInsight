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
    int N, M;
    cin >> N >> M;
    int A[100010];
    rep(i, N) cin >> A[i];
    
    int sum[100010] = {};
    map<int, int> mp;
    rep(i, N) {
        sum[i + 1] = (sum[i] + A[i]) % M;
        mp[sum[i + 1]]++;
    }
    int ans = mp[0];
    int S = 0;  
    rep(i, N) {
        ans += mp[sum[i + 1]] - 1;
        mp[sum[i + 1]]--;
    }
    cout << ans << endl;



    return 0;
}
