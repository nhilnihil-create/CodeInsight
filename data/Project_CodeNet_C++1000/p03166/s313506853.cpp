#include <bits/stdc++.h>

#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

typedef long long ll;
typedef long double ld;

int N, M;
vector<vector<int>> adj_mat;
vector<int> max_path_len;

int dfs(int i)
{
    if (max_path_len[i] == INT_MIN)
    {
        max_path_len[i] = 0;
        for (auto j : adj_mat[i])
            max_path_len[i] = max(max_path_len[i], 1 + dfs(j));
    }
    return max_path_len[i];
}

int main()
{
    fastIO;
    cin >> N >> M;
    adj_mat.resize(N + 1);
    max_path_len.resize(N + 1, INT_MIN);
    int x, y;
    while (M--)
    {
        cin >> x >> y;
        adj_mat[x].push_back(y);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = max(ans, dfs(i));
    cout << ans;
}