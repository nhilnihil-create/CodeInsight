#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int N;
    ll A, B;
    cin >> N >> A >> B;
    vector<int> X(N);
    map<int, int> M;
    rep(i, N) {
        cin >> X[i];
        M[X[i]] = i;
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
    rep(i, N + 1) dp[i][0] = B * i;
    rep(i, 1, N + 1) {
        ll mi = dp[i - 1][1];
        rep(j, 1, N + 1) {
            if(j - 1 < M[i]) dp[i][j] = mi + B;
            else if(j - 1 > M[i]) dp[i][j] = mi + A;
            else dp[i][j] = mi;
            if(j != N) mi = min(mi, dp[i - 1][j + 1]);
        }
    }
    ll ans = dp[N][0];
    rep(i, N + 1) {
        ans = min(ans, dp[N][i]);
    }
    output(ans);
    
    return 0;
}
