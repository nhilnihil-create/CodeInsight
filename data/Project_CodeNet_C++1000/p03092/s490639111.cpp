#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 100000000000000000;

ll dp[5002][5002];

int main()
{
    int n;
    ll a, b;
    cin >> n >> a >> b;
    int p[5002], q[5002];
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
        q[p[i]] = i;
    }
    int left[5002], right[5002];
    fill(left, left + n, n);
    fill(right, right + n, -1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < q[i]; j++){
            if(p[j] > i) left[i] = min(left[i], p[j]);
        }
        for(int j = q[i] + 1; j < n; j++){
            if(p[j] < i) right[i] = max(right[i], p[j]);
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++) dp[i][j] = INF;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(dp[i - 1][j] == INF) continue;
            if(j > p[i - 1] + 1) dp[i][j] = dp[i - 1][j] + b;
            else dp[i][j] = dp[i - 1][j] + a;
        }
        for(int j = 0; j < p[i - 1] + 1; j++) dp[i][p[i - 1] + 1] = min(dp[i][p[i - 1] + 1], dp[i - 1][j]);
    }
    ll ans = INF;
    for(int j = 0; j <= n; j++) ans = min(ans, dp[n][j]);
    cout << ans << endl;
}
