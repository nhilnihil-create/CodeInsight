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

int A[2010];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K, Q;
    cin >> N >> K >> Q;
    rep(i, N) cin >> A[i];
    int ans = INF;
    rep(i, N) {
        vector<int> v1;
        vector<int> v2;
        int X = 0;
        rep(j, N) {
            if (A[i] <= A[j]) {
                v1.push_back(A[j]);
            }
            if (j == N - 1 || A[i] > A[j]) {
                sort(v1.begin(), v1.end());
                rep(k, (int)v1.size() - K + 1) {
                    v2.push_back(v1[k]);
                }
                v1.clear();
            }
        }
        if (v2.size() >= Q) {
            sort(v2.begin(), v2.end());
            rep(j, Q) {
                X = max(X, v2[j]);
            }
            ans = min(ans, X - A[i]);
        }
        // cout << v2.size() << " " << X << " " << A[i] << endl;
        // rep(j, v2.size()) {
        //     cout << v2[j] << " ";
        // }
        // cout << endl;
    }
    cout << ans << endl;

    return 0;
}
