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

ll dp[410][410];
ll a[410], acc[410];

int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n) acc[i+1] = acc[i] + a[i];

    for (int w = 2; w <= n; w++){
        for (int l = 0; l+w <= n; l++){
            int r = l + w;
            ll tmp = LINF;
            for(int m = l+1; m < r; m++){
                ll cost1 = acc[m] - acc[l];
                ll cost2 = acc[r] - acc[m];
                tmp = min(tmp, dp[l][m] + dp[m][r] + cost1 + cost2);
            }
            dp[l][r] = tmp;
        }
    }

    cout << dp[0][n] << endl;

    return 0;
}
