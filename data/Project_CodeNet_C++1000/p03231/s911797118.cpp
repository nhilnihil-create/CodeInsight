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
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}
map<int, char> mp;
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    if (N < M) {
        swap(N, M);
        swap(S, T);
    }
    int L = N * M / gcd(N, M);
    rep(i, N) mp[L/N * i] = S[i];
    rep(i, M) {
        if (mp.find(L/M * i) == mp.end()) continue;
        if (mp[L/M * i] != T[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << L << endl;

    return 0;
}
// L = 6
// N = 6
// 1, 2, 3, 4, 5, 6
// M = 3
// 1, 3, 5
