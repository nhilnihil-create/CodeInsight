#include <bits/stdc++.h>

using namespace std;

int n, m, lq;
char s[200010];
vector<int> g[200010];
int v[2][200010];
int q[200010];
int inq[200010];

int main()
{
    scanf("%d%d%s", &n, &m, s);
    for(int i = 0; i < n; i++)
        s[i] -= 'A';
    for(int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        g[a].push_back(b);
        v[s[b]][a]++;
        if(a != b)
        {
            g[b].push_back(a);
            v[s[a]][b]++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(v[0][i] == 0 || v[1][i] == 0)
        {
            inq[i] = 1;
            q[lq++] = i;
        }
    }
    int r = 0;
    while(r < lq)
    {
        int k = q[r];
        for(int i = 0; i < g[k].size(); i++)
        {
            v[s[k]][g[k][i]]--;
            if(v[s[k]][g[k][i]] == 0)
            {
                if(inq[g[k][i]] == 0)
                {
                    inq[g[k][i]] = 1;
                    q[lq++] = g[k][i];
                }
            }
        }
        r++;
    }
    if(lq != n)
        printf("Yes");
    else printf("No");
    return 0;
}
