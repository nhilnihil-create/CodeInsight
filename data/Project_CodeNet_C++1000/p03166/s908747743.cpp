#include <bits/stdc++.h>
#define N 100007
using namespace std;
vector <int> adj[N];
int mem[N];
int dp(int i)
{
    if(mem[i] != -1)
        return mem[i];
    int ans = 0;
    for(int j = 0;j < adj[i].size();j++)
    {
        int k = dp(adj[i][j]);
        ans = max(ans, k);
    }
    ans += 1;
    mem[i] = ans;
    return ans;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    memset(mem, -1, sizeof(mem));
    for(int i = 0;i < m;i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int mx = 0;
    for(int i = 1;i < N;i++)
    {
        int k = dp(i);
        if(k > mx)
            mx = k;
    }
    cout << mx-1 << endl;
    return 0;
}