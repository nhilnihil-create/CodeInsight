#include <bits/stdc++.h>
using namespace std;
#define int long long
int inf = 10e17;
#define mod 1000000007
int findLowerBound(
    vector<pair<int, int>> &arr,
    pair<int, int> &p)
{

    auto low = lower_bound(arr.begin(),
                           arr.end(), p);

    return low - arr.begin();
}
int findUpperBound(
    vector<pair<int, int>> &arr,
    pair<int, int> &p)
{
    auto up = upper_bound(arr.begin(),
                          arr.end(), p);

    return up - arr.begin();
}
bool vis[200005];
vector<int> vec[2000005];
int child[2000005];
int parent[2000005];
int div1[100005];
void dfs(int node)
{
    vis[node] = 1;
    for (int i = 0; i < vec[node].size(); i++)
    {
        if (!vis[vec[node][i]])
        {
            parent[vec[node][i]] = node;
            dfs(vec[node][i]);
            //   child[node] += child[vec[node][i]];
        }
    }
}
void bfs(int node)
{
    queue<int> qu;
    qu.push(node);
    vis[1] = 1;
    while (!qu.empty())
    {
        int top = qu.front();
        //cout << qu.front() << "\n";
        qu.pop();
        vis[top] = 1;
        for (int i = 0; i < vec[top].size(); i++)
        {
            if (!vis[vec[top][i]])
            {
                parent[vec[top][i]] = top;
                qu.push(vec[top][i]);
                vis[vec[top][i]] = 1;
            }
        }
    }
}
void belman(int n, int m, vector<pair<int, pair<int, int>>> vec, int dis[])
{
    for (int i = 0; i <= n + m - 1; i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            int u = vec[j].second.first;
            int v = vec[j].second.second;
            int w = vec[j].first;

            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
        }
    }
}
int fun(int a, int b)
{
    if (a > b)
        return 0;
    if (a == b)
        return 1;
    else
    {
        return fun(a + 1, b) + fun(a, b - a);
    }
}
int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;
    sort(str1.begin(), str1.end(), greater<char>());
    sort(str2.begin(), str2.end(), greater<char>());
    //  cout << str1 << " " << str2 << "\n";
    //cerr << "kcsc"
    //   << "\n";

    for (int i = 0; i < str1.length(); i++)
    {
        for (int j = 0; j < str2.length(); j++)
        {
            if (str2[j] > str1[i])
            {
                cout << "Yes"
                     << "\n";
                return 0;
            }
        }
    }
    if (str2 > str1)
    {
        cout << "Yes"
             << "\n";
    }
    else

        cout << "No"
             << "\n";

    return 0;
}
