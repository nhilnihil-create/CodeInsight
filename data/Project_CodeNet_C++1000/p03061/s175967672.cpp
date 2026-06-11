#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
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
int gcd(int a, int b){
    if(b > a) return gcd(b, a);
    else if(b == 0) return a;
    else return gcd(b, a % b);
}
int L[100010], R[100010];
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int A[100010];
    rep(i, N) cin >> A[i];
    L[0] = R[N] = 0;
    rep(i, N) {
        L[i + 1] = gcd(L[i], A[i]);
    }
    RREP(i, N - 1, 0) {
        R[i] = gcd(R[i + 1], A[i]);
    }
    int ans = 1;
    rep(i, N) {
        ans = max(ans, gcd(L[i], R[i + 1]));
    }
    cout << ans << endl;

    return 0;
}
