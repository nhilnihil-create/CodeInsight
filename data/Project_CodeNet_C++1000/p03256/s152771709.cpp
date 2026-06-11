#include <bits/stdc++.h>
using namespace std;

const int N = 200006;

vector<int> G[N];

int a[N];
int cnt[2][N];
int vis[N];

bool fail(int x)
{
    return cnt[0][x] == 0 || cnt[1][x] == 0;
}

int main ()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i=0;i<m;++i)
    {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i=0;i<n;++i)
    {
        if (s[i] == 'A') a[i+1] = 1;
        else a[i+1] = 0;
    }
    for (int i=1;i<=n;++i)
    {
        for (int j:G[i])
        {
            cnt[ a[i] ][j]++;
        }
    }
    queue<int> que;
    int cntt=0;
    for (int i=1;i<=n;++i)
    {
        if (fail(i))
        {
            vis[i] = true;
            que.push(i);
        }
    }
    while (!que.empty())
    {
        ++cntt;
        int x=que.front();
        que.pop();
        for (int j:G[x])
        {
            cnt[ a[x] ][j]--;
            if (!vis[j] && fail(j))
            {
                que.push(j);
                vis[j] = true;
            }
        }
    }
    if (cntt == n) puts("No");
    else puts("Yes");
}

