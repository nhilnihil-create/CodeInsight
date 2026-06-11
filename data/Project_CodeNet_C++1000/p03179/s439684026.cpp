#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    while (a >= MOD) 
        a -= MOD;
    while (a < 0)
        a += MOD;
}

char comp(int x, int y) {
    if (x < y)
        return '<';
    return '>';
}

int main() {
    int n; cin >> n;
    string s; cin >> s;
    
    vector<vector<int>> dp(n, vector<int> (n + 1, 0));
    vector<vector<int>> part(n, vector<int> (n + 1, 0));

    dp[0][1] = 1;
    part[0] = vector<int> (n + 1, 1);
    part[0][0] = 0;

    auto getSum = [&] (int lf, int rt, auto& part) {
        int ans = part[rt];
        if (lf - 1 >= 0)
            add(ans, -part[lf - 1]);
        return ans;
    };

    for (int i = 1; i < n; i += 1)
        for (int j = 1; j <= n; j += 1) {
            if (j <= i + 1) {
                if (s[i - 1] == '<')
                    dp[i][j] = getSum(1, j - 1, part[i - 1]);
                else
                    dp[i][j] = getSum(j, n, part[i - 1]);
            }
            part[i][j] = dp[i][j];
            add(part[i][j], part[i][j - 1]);
        }

    int ans = 0;
    for (int i = 1; i <= n; i += 1)
        add(ans, dp[n - 1][i]);

    cout << ans << "\n";
}