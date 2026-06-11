#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    VI p(n);
    REP(i,n) p[i] = in() - 1;
    VL c(n, b);

    VVL dp(n + 1, VL(n + 1, 1e18));
    dp[0][0] = 0;
    REP(i,n+1){
        REP(j,n) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + c[j]);
        if (i < n){
            REP(j,n+1) dp[i+1][j] = dp[i][j];
            dp[i+1][p[i]+1] = dp[i][p[i]];
            c[p[i]] = a;
        }
    }
    cout << dp[n][n] << endl;

    return 0;
}
