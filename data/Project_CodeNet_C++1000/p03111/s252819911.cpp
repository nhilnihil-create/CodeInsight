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
    int N, A[3];
    cin >> N >> A[0] >> A[1] >> A[2];
    int l[8];
    rep(i, N) cin >> l[i];
    int ans = INF;
    int pattern = 1;
    rep(i, N) pattern *= 4;
    rep(bit, pattern) {
        int tmp = bit;
        vector<int> v[3];
        int sum[3] = {};
        rep(i, N) {
            if(tmp % 4 != 3) {
                v[tmp % 4].push_back(l[i]);
                sum[tmp % 4] += l[i];
            }
            tmp /= 4;
        }
        bool ok = true;
        rep(i, 3) if(v[i].size() == 0) ok = false;
        if(!ok) continue;
        int cost = 0;
        rep(i, 3) {
            cost += abs(sum[i] - A[i]);
            cost += (v[i].size() - 1) * 10;
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;


    return 0;
}
