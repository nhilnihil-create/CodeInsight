#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

#define MAX 4000000

signed main() {
    int n;
    cin >> n;
    int sum = 0;
    int a[n];
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    bitset<MAX + 1> dp;
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        dp |= dp << a[i];
    }
    for (int i = (sum + 1) / 2; i <= sum; i++) {
        if (dp[i]) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}