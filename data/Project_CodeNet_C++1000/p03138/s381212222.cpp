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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

ll a[100010];
ll dp[110][2];

int main(){
    ll n, k;
    cin >> n >> k;
    rep(i, n) cin >> a[i];

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    rep(d, 100){
        ll mask = 1ll<<(50 - d - 1);
        ll cnt = 0;
        rep(i, n) if (mask & a[i]) cnt++;
        ll cost0 = cnt * mask;
        ll cost1 = (n - cnt) * mask;

        if (dp[d][1] != -1) {
            chmax(dp[d+1][1], dp[d][1] + max(cost0, cost1));
        }
        
        if (dp[d][0] != -1) {
            if (k & mask) {
                chmax(dp[d+1][1], dp[d][0] + cost0);
            }
        }
        
        if (dp[d][0] != -1) {
            if (k & mask) chmax(dp[d+1][0], dp[d][0] + cost1);
            else chmax(dp[d+1][0], dp[d][0] + cost0);
        }
    }

    cout << max(dp[50][0], dp[50][1]) << endl;

    return 0;
}
