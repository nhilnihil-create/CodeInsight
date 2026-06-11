#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <iostream>
using namespace std;

int main() {
        string s;
        cin >> s;
        int k;
        scanf("%d", &k);
        int n = s.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (n + 1, vector<int> (n + 1, -1)));
        function<int (int, int, int)> calc = [&](int l, int r, int t) {
                if (dp[l][r][t] != -1) return dp[l][r][t];
                if (l > r) return 0;
                if (l == r) return 1;
                int ma = 0;
                if (s[l] == s[r]) ma = max(ma, calc(l + 1, r - 1, t) + 2);
                ma = max(ma, calc(l + 1, r, t));
                ma = max(ma, calc(l, r - 1, t));
                if (t > 0) ma = max(ma, calc(l + 1, r - 1, t - 1) + 2);
                return dp[l][r][t] = ma;
        };
        printf("%d\n", calc(0, n - 1, k));
        return 0;
}
