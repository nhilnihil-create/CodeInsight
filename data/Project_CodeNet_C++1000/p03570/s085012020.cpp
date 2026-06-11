#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;

int dp[1 << 26], a[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        a[i + 1] = a[i] ^ (1 << (s[i] - 'a'));
    }
    fill_n(dp, 1 << 26, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int tmp = INF;
        for (int j = 0; j < 26; j++) {
            tmp = min(tmp, dp[a[i + 1] ^ (1 << j)]);
        }
        dp[a[i + 1]] = min(dp[a[i + 1]], tmp + 1);
    }
    cout << max(dp[a[n]], 1) << endl;
    return 0;
}