#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const ll INF = 1e18;
const int N = 5005;
ll dp[N][N];
int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, A, B;
    cin >> n >> A >> B;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j < a[i]) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + A);
            }
            else if (j > a[i]) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + B);
            }
        }
        for (int j = 0; j < a[i]; j++)  {
            dp[i + 1][a[i]] = min(dp[i + 1][a[i]], dp[i][j]);
        }
    }

    ll ans = INF;

    for (int i = 0; i <= n; i++) {
        ans = min(ans, dp[n][i]);
    }

    cout << ans << "\n";

    return 0;
}