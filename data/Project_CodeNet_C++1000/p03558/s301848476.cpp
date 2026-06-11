#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int K;
int A[100010];

void solve(int p, int q) {
    if (A[p] <= q) return;
    A[p] = q;
    //cout << "A[" << p << "] = " << A[p];
    solve((p * 10) % K, q);
    solve((p + 1) % K, q + 1);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> K;
    rep(i, K+1) A[i] = 99;
    solve(1, 1);
    cout << A[0] << endl;

    return 0;
}
