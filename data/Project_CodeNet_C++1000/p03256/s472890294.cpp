#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 200005;

int n, m, u, v, cnt[N][2];
bool chk[N];
char s[N];
vector<int> ve, adj[N];

int main()
{
    scanf("%d %d\n%s\n", &n, &m, s + 1);
    for (int i = 1; i <= n; i++)
        s[i] -= 'A';
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d\n", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        cnt[u][s[v]]++;
        cnt[v][s[u]]++;
    }
    for (int i = 1; i <= n; i++)
        if (cnt[i][0] == 0 || cnt[i][1] == 0)
        {
            ve.push_back(i);
            chk[i] = true;
        }
    for (unsigned int i = 0; i < ve.size(); i++)
    {
        int u = ve[i];
        for (int &v : adj[u])
            if (!chk[v] && (--cnt[v][s[u]]) == 0)
            {
                ve.push_back(v);
                chk[v] = true;
            }
    }
    printf("%s\n", ve.size() == n ? "No" : "Yes");
}