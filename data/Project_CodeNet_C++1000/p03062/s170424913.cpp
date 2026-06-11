#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
//const int inf = int(1e10);
const ll inf = ll(1e19);
const int mod = int(1e9) + 7;

ll n, a[int(1e5)], res;
//i番目までの要素に対して操作を行った時の最大値
ll dp[int(1e5)][2];
int main(){
    cin >> n;
    rep(i, n){
        cin >> a[i];
        res += a[i];
    }
    rep(i, int(1e5)){
        dp[i][0] = -inf;
        dp[i][1] = -inf;
    }
    dp[0][0] = a[0] + a[1];
    dp[0][1] = -(a[0] + a[1]);
    for(int i = 0; i < n - 2; i++){
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + a[i + 2]);
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + a[i + 2]);
        //cout << i << ' ' << dp[i + 1][0] << endl;
        dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] - 2 * a[i + 1] - a[i + 2]);
        dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + 2 * a[i + 1] - a[i + 2]);
        //cout << i << ' ' << dp[i + 1][1] << endl;
    }

    cout << max(dp[n - 2][0], dp[n - 2][1]) << endl;
}