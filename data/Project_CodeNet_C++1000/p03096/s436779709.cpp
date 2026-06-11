#include <bits/stdc++.h>

using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// cout << fixed << setprecision(20);
int N;
int C[220000];
int dp[220000];
int mod = 1e9 + 7;

signed main() {
    cin >> N;
    for (int i = 1; i <= N; i++)cin >> C[i];
    int ans = 1;
    for (int i = 1; i <= N; i++) {
        if (C[i] == C[i - 1])continue;
        ans = dp[C[i]] = (ans + dp[C[i]]) % mod;
    }
    cout << ans << endl;
}
