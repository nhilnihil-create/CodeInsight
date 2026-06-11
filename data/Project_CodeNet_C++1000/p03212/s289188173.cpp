
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int n;


int solve(int i, bool a, bool b, bool c, bool up) {
    if (i == n) {
        if (a && b && c)
            return 1;
        return 0;
    }
    if (up) {
        int u = s[i] - '0';
        if (u < 3) return 0;
        if (u == 3) return solve(i + 1, true, b, c, true);
        if (u < 5) return solve(i + 1, true, b, c, false);
        if (u == 5) return solve(i + 1, true, b, c, false) + solve(i + 1, a, true, c, true);
        if (u < 7) return solve(i + 1, true, b, c, false) + solve(i + 1, a, true, c, false);
        if (u == 7) return solve(i + 1, true, b, c, false) + solve(i + 1, a, true, c, false)
            + solve(i + 1, a, b, true, true);
        return solve(i + 1, true, b, c, false)
        + solve(i + 1, a, true, c, false)
        + solve(i + 1, a, true, c, false);
    } else {
        if (a && b && c) {
            return pow(3, n - i);
        }
        return solve(i + 1, a, b, true, false) + solve(i + 1, a, true, c, false) +
            solve(i + 1, true, b, c, false);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    n = s.length();
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += solve(i, false, false, false, i == 0);
    }
    cout << res << endl;

    return 0;
}

