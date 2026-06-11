#include <bits/stdc++.h>

using namespace std;

string s;

int dp[305][305][305];

int dfs(int l, int r, int k)
{
    if(r < l)
        return 0;
    if(l == r)
        return 1;
    int &res = dp[l][r][k];
    if(res != -1)
        return res;
    res = max(dfs(l, r - 1, k), dfs(l + 1, r, k));
    if(s[l] == s[r])
        res = max(res, dfs(l + 1, r - 1, k) + 2);
    if(k)
        res = max(res, dfs(l + 1, r - 1, k - 1) + 2);
    return res;

}

int main()
{
    int k;
    cin >> s >> k;
    memset(dp, -1, sizeof dp);

    cout << dfs(0, s.size() - 1, k);

    return 0;

}