#include <bits/stdc++.h>

#define MAX_N 100000

#define pb push_back

#define xx first
#define yy second

using namespace std;

int n;

vector <pair<int, int>> g[MAX_N + 1];
vector <pair<int, int>> tata[MAX_N + 1];

int poz[MAX_N + 1];

bool viz[MAX_N + 1];
bool luat[MAX_N + 1];

void out()
{
    cout << "No\n";

    exit(0);
}

void add(int a, int b, int c)
{
    luat[b] = 1;

    g[a].pb({b, c});
}

void rev(int a, int b, int c)
{
    tata[a].pb({b, c});
}

void dfs(int a)
{
    viz[a] = 1;
    for(auto u : g[a])
    {
        if(viz[u.xx] == 0)
        {
            poz[u.xx] = poz[a] + u.yy;
            dfs(u.xx);
        }

        else
            if(poz[u.xx] != poz[a] + u.yy)
                out();
    }

    for(auto u : tata[a])
    {
        if(viz[u.xx] == 0)
        {
            poz[u.xx] = poz[a] - u.yy;
            dfs(u.xx);
        }

        else
            if(poz[u.xx] != poz[a] - u.yy)
                out();
    }
}

int main()
{
    int m;
    cin >> n >> m;

    int i;
    int a, b, c;
    for(i = 1; i <= m; i ++)
    {
        cin >> a >> b >> c;

        add(a, b, c);
        rev(b, a, c);
    }

    for(i = 1; i <= n; i ++)
        poz[i] = -1;

    for(i = 1; i <= n; i ++)
    {
        if(viz[i] == 0)
        {
            poz[i] = 0;
            dfs(i);
        }
    }


    cout << "Yes\n";

    return 0;
}
