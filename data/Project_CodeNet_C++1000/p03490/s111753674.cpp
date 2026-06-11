#include <bits/stdc++.h>

using namespace std;

const int maxN = 8005;

int n, x, y;
vector<int> dx, dy;
char s[maxN];

bool Check(int x, const vector<int> &d) {
    if (x < -n || x > n) return false;
    vector<bool> dp[2];
    for(int i = 0; i < 2; ++i)
        dp[i].assign(2*n+1, false);
    dp[0][n] = true;

    for(int i = 0; i < d.size(); ++i) {
        for(int j = 0; j < 2*n; ++j) {
            if (dp[0][j]) dp[1][j-d[i]] = dp[1][j+d[i]] = true;
        }
        for(int j = 0; j < 2*n; ++j) {
            dp[0][j] = dp[1][j];
            dp[1][j] = false;
        }
    }

    return dp[0][n+x];
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    scanf("%d%d", &x, &y);

    dx.clear(); dy.clear();
    int cur = 0, group = 0;
    for(int i = 0; i <= n; ++i) {
        if (i < n && s[i] == 'F') ++cur;
        else {
            ++group;
            if (group == 1) x -= cur;
            else if (group%2 == 0) dy.push_back(cur);
            else dx.push_back(cur);
            cur = 0;
        }
    }

    bool ans = Check(x, dx) && Check(y, dy);
    puts((ans) ? "Yes" : "No");
}
