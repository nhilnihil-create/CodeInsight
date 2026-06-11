#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
const int inf = 1e9;

const int MAX = 1 << 26;
int dp[MAX];

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> a(n);
    a[0] = (1 << (s[0] - 'a'));
    rep(i, n - 1) {
        a[i + 1] += a[i] ^ (1 << (s[i + 1] - 'a'));
    }

    rep(i, MAX) dp[i] = inf;
    dp[0] = 0;

    rep(i, n) {
        int t = inf;
        t = min(t, dp[a[i]] + 1);
        rep(j, 26) {
            t = min(t, dp[a[i] ^ (1 << j)] + 1);
        }
        if (i == n - 1) {
            cout << t << endl;
            return 0;
        }
        dp[a[i]] = min(dp[a[i]], t);
    }
}
