#include <bits/stdc++.h>

#define MAX_N 200000

using namespace std;

string s;

int n, m;

vector <int> g[MAX_N + 1];

int ap[MAX_N + 1][2];

int que[MAX_N + 1];

void add(int a, int b)
{
    g[a].push_back(b);
}

int luat[MAX_N + 1];

int main()
{
    cin >> n >> m;

    cin >> s;

    int i;
    int a, b;
    for(i = 1; i <= m; i ++)
    {
        cin >> a >> b;

        add(a, b);

        if(a != b)
            add(b, a);
    }

    for(i = 1; i <= n; i ++)
    {
        for(auto u : g[i])
            ap[u][s[i - 1] - 'A'] ++;

    }

    int st = 1, dr = 0;
    for(i = 1; i <= n; i ++)
    {
        if(ap[i][0] < 1 || ap[i][1] < 1)
        {
            luat[i] = 1;
            que[++ dr] = i;
        }
    }

    while(st <= dr)
    {
        int cr = que[st ++];

        for(auto u : g[cr])
        {
            ap[u][s[cr - 1] - 'A'] --;

            if(luat[u] == 0 && (ap[u][0] < 1 || ap[u][1] < 1))
            {
                luat[u] = 1;
                que[++ dr] = u;
            }
        }
    }

    int rez = 0;
    for(i = 1; i <= n; i ++)
        rez = rez || (luat[i] == 0);

    cout << (rez == 1 ? "Yes\n" : "No\n");

    return 0;
}
