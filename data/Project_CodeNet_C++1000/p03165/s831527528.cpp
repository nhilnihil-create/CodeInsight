#include <bits/stdc++.h>
using namespace std;

const int mxN = 3e3 + 2;
string s, t;
int n, m, dp[mxN][mxN];
pair<int, int> parent[mxN][mxN];

int calc(int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    return dp[i][j];
}

int main()
{
    cin >> s >> t;
    n = s.length(); m = t.length();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {            dp[i][j] = 0;
            if (calc(i - 1, j) >= dp[i][j])
            {
                parent[i][j] = {i - 1, j};
                dp[i][j] = calc(i - 1, j);
            }
            if (calc(i, j - 1) >= dp[i][j])
            {
                parent[i][j] = {i, j - 1};
                dp[i][j] = calc(i, j - 1);
            }
            if (s[i] == t[j] && calc(i - 1, j - 1) + 1 >= dp[i][j])
            {
                parent[i][j] = {i - 1, j - 1};
                dp[i][j] = calc(i - 1, j - 1) + 1;
            }
        }
    }

    string ret = "";
    pair<int, int> cur = {n - 1, m - 1};
    while (cur.first >= 0 && cur.second >= 0)
    {
        if (s[cur.first] == t[cur.second])
            ret.push_back(s[cur.first]);
        cur = parent[cur.first][cur.second];
    }
    reverse(ret.begin(), ret.end());

    cout << ret << endl;
}