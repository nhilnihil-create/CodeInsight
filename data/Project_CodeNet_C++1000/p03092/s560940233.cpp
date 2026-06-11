#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, A, B;
    cin >> n >> A >> B;
    vector<int> a(n+2);
    a[0] = 0; a[n+1] = n+1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> dp(n+2, 1ll<<60);
    dp[0] = 0;
    for (int i = 1; i <= n+1; i++) {
        int cnt = 0;
        for (int j = i-1; j >= 0; j--) {
            if (a[j] < a[i]) {
                dp[i] = min(dp[i], dp[j] + 1ll*cnt*A + 1ll*(i-1-j-cnt)*B);
            } else {
                cnt++;
            }
        }
    }
    cout << dp[n+1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cout << endl;
}
