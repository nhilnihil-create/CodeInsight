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

int A[20010];
int a[4] = {1, 1, 2, 2};

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    if (N == 3) {
        cout << "2 5 63" << endl;
        return 0;
    }
    if (N == 4) {
        cout << "2 5 20 63" << endl;
        return 0;
    }
    int sum = 2;
    A[0] = 2;
    rep(i, N - 1) {
        A[i + 1] = A[i] + a[i % 4];
        sum = (sum + A[i + 1]) % 6;
    }
    A[N - 1] += (6 - sum) % 6;
    if (A[N - 1] % 6 == 1 || A[N - 1] % 6 == 5) {
        A[N - 1]--;
        A[N - 2]++;
    }
    rep(i, N) {
        if (i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl;


    return 0;
}
