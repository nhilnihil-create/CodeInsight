#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<ld> vld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INF ((int)1e9)
#define INFLL ((ll)1e18)
#define MOD (1000000007LL)


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int N;
    ll A, B;
    cin >> N >> A >> B;
    vi p(N+1);
    for (int n = 1; n <= N; ++n) {
        cin >> p[n];
    }
    vi q(N+1);
    for (int n = 1; n <= N; ++n) {
        q[p[n]] = n;
    }
    
    vvll dp(N+1, vll(N+1));
    for (int n = 0; n <= N; ++n) {
        dp[0][n] = 0;
    }
    for (int m = 1; m <= N; ++m) {
        dp[m][0] = dp[m-1][0];
        for (int n = 1; n <= N; ++n) {
            dp[m][n] = min(dp[m-1][n], dp[m][n-1]);
        }
        
        for (int n = 0; n < q[m]; ++n) {
            dp[m][n] += B;
        }
        for (int n = q[m]+1; n <= N; ++n) {
            dp[m][n] += A;
        }
        
    }
    
    ll ans = INFLL;
    for (int n = 0; n <= N; ++n) {
        if (ans > dp[N][n]) {
            ans = dp[N][n];
        }
    }
    cout << ans << endl;

    return 0;
}
