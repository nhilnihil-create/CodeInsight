#include<bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple

using namespace std;

int niz[100010];
int mapa[100010];
int mark[100010];
vector<int> graf[100010];

void dfs(int x, int boja)
{
    mark[x] = boja;
    for(int i = 0; i < graf[x].size(); i++)
    {
        int cvor = graf[x][i];
        if(mark[cvor] == 0) dfs(cvor, boja);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> niz[i];
        mapa[niz[i]] = i;
    }
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graf[a].pb(b);
        graf[b].pb(a);
    }
    int boja = 1;
    for(int i = 1; i <= n; i++)
    {
        if(mark[i] == 0)
        {
            dfs(i, boja);
            boja++;
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
        if(mark[mapa[i]] == mark[i]) res++;

    cout << res;

    return 0;
}
