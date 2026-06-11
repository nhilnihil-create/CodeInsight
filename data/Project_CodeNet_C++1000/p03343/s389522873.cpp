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
    int N, K, Q;
    cin >> N >> K >> Q;
    int A[2010];
    rep(i, N) cin >> A[i];
    int ans = INF;
    rep(i, N) {
        vector<int> v1, v2;
        rep(j, N) {
            if (A[j] >= A[i]) {
                v1.push_back(A[j]);
            } else {
                if (v1.size() >= K) {
                    sort(v1.begin(), v1.end());
                    rep(k, v1.size() - K + 1) {
                        v2.push_back(v1[k]);
                    }
                }
                v1.clear();
            }
        }
        if (v1.size() >= K) {
            sort(v1.begin(), v1.end());
            rep(k, v1.size() - K + 1) {
                v2.push_back(v1[k]);
            }
        }
        sort(v2.begin(), v2.end());
        if(v2.size() >= Q) {
            ans = min(ans, v2[Q - 1] - v2[0]);
        }
        
    }
    cout << ans << endl;

    return 0;
}
