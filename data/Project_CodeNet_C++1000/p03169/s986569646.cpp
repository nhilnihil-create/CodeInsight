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

 int n;
 int cnt [4];
 double dp[330][330][330];

int main(){
    cin >> n;
    rep(i, n){
        int a;
        cin >> a;
        cnt[a]++;
    }
    rep(i, n+1){
        rep(j, n+1){
            rep(k, n+1){
                if (i+j+k == 0) {
                    dp[i][j][k] == 0;
                    continue;
                }
                dp[i][j][k] += (double) n / (i+j+k);
                if (i > 0) dp[i][j][k] += dp[i-1][j+1][k] * i / (i+j+k);
                if (j > 0) dp[i][j][k] += dp[i][j-1][k+1] * j/ (i+j+k);
                if (k > 0) dp[i][j][k] += dp[i][j][k-1] * k / (i+j+k);
            }
        }
    }
    
    cout << fixed << setprecision(10) << dp[cnt[3]][cnt[2]][cnt[1]] << endl;

    return 0;
}
