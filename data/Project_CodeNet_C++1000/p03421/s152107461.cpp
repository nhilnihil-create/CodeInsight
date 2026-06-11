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
    int N, A, B;
    cin >> N >> A >> B;
    if(A * B < N || N + 1 < A + B) {cout << -1 << endl; return 0;}
    vector<int> v[B];
    int cnt = 0;
    rep(i, A) v[0].push_back(i + 1);
    REP(i, A + 1, N) {v[cnt % (B - 1) + 1].push_back(i); cnt++;}
    cnt = 0;
    RREP(i, B - 1, 0) {
        rep(j, v[i].size()) {
            if (cnt != 0) cout << " ";
            cout << v[i][j];
            cnt++;
        }
    }
    cout << endl;


    return 0;
}
// 7
// 6
// 1 2 3 4 5