#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)
typedef long long ll;

using namespace std;

template <typename T> void output(T, int);
template <typename T> T max(T, T);
int gcd(int a, int b);

int main() {
    // source
    ll mod = pow(10, 9) + 7;
    string s;
    cin >> s;
    ll dp[s.size()][4] = {};

    if (s[0] == 'A') {
        dp[0][0] = 1;
        dp[0][1] = 1;
    } else if (s[0] == '?') {
        dp[0][0] = 3;
        dp[0][1] = 1;
    } else {
        dp[0][0] = 1;
    }
    rep(j, 4) { dp[0][j] %= mod; }

    repd(i, 1, s.size()) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 1][2];
        dp[i][3] = dp[i - 1][3];
        if (s[i] == 'A') {
            dp[i][1] += dp[i - 1][0];
        }
        if (s[i] == 'B') {
            dp[i][2] += dp[i - 1][1];
        }
        if (s[i] == 'C') {
            dp[i][3] += dp[i - 1][2];
        }
        if (s[i] == '?') {
            dp[i][0] = dp[i - 1][0] * 3;
            dp[i][1] = dp[i - 1][1] * 3 + dp[i - 1][0];
            dp[i][2] = dp[i - 1][2] * 3 + dp[i - 1][1];
            dp[i][3] = dp[i - 1][3] * 3 + dp[i - 1][2];
        }

        rep(j, 4) { dp[i][j] %= mod; }
    }

    cout << dp[s.size() - 1][3] << endl;
    return 0;
}

template <typename T> void output(T a, int precision) {
    if (precision > 0) {
        cout << setprecision(precision) << a << "\n";
    } else {
        cout << a << "\n";
    }
}

template <typename T> T max(T a, T b) {

    if (a > b) {
        return a;
    } else {
        return b;
    }
}

template <typename T> T min(T a, T b) {

    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
