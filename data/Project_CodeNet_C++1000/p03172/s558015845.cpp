#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll dp[110][100010]; // i番目までの子にj個配るパターン数
ll a[110];

int main(){
    int n, k;
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    dp[0][0] = 1;
    rep(i, n){
        ll acc[k+10] = {};
        rep(j, k+1) {
            acc[j+1] += dp[i][j] + acc[j];
            acc[j+1] %= MOD;
        }
        rep(j, k+1){
            dp[i+1][j] += acc[j+1] - acc[max((ll)0, j-a[i])] + MOD;
            dp[i+1][j] %= MOD;
        }
    }
    cout << (dp[n][k] + MOD) % MOD << endl;
    return 0;
}