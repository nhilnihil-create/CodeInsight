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
    int N, K, Q;
    cin >> N >> K >> Q;
    int A[2010];
    int ans = INF2;
    rep(i, N) cin >> A[i];
    rep(i, N) {
        vector<int> all;
        rep(j, N) {
            vector<int> v;
            while (j < N && A[j] >= A[i]) v.push_back(A[j++]);
            if (v.size() < K) continue;
            sort(v.begin(), v.end());
            rep(k, v.size() - K + 1) {
                all.push_back(v[k]);
            }
        }
        sort(all.begin(), all.end());
        if (all.size() >= Q) {
            ans = min(ans, all[Q - 1] - all[0]);
        }
    }
    cout << ans << endl;


    return 0;
}
