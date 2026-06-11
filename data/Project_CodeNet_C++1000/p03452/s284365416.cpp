#include <bits/stdc++.h>
#define NMAX 100010
#define MMAX 200010

using namespace std;

struct Link
{
    int l, r, d, gr;

    int other(int x) const
    {
        return x == l ? r : l;
    }
} v[MMAX];

int vizgr[NMAX];
int t[NMAX];
int arepos[NMAX];
int pos[NMAX];
vector<int> g[NMAX];

int tata(int n)
{
    if(t[n] == n)
        return n;
    int r = tata(t[n]);
    t[n] = r;
    return r;
}

int main() {
    //freopen("in.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        t[i] = i;
    for(int i = 0; i < m; i++)
    {
        cin >> v[i].l >> v[i].r >> v[i].d;

        g[v[i].l].push_back(i);
        g[v[i].r].push_back(i);

        int tl = tata(v[i].l);
        int tr = tata(v[i].r);
        t[tl] = tr;
    }
    queue<int> q;
    for(int i = 0; i < m; i++) {
        v[i].gr = tata(v[i].l);
        if(vizgr[v[i].gr] == 0) {
            vizgr[v[i].gr] = 1;

            arepos[v[i].l] = 1;
            pos[v[i].l] = 0;
            q.push(v[i].l);
        }
    }
    while(!q.empty())
    {
        int nod = q.front();
        q.pop();

        for(int vecid : g[nod])
        {
            if(arepos[v[vecid].other(nod)] == 1)
            {
                if(pos[v[vecid].r] - pos[v[vecid].l] != v[vecid].d)
                {
                    cout << "No";
                    return 0;
                }
            }
            else
            {
                arepos[v[vecid].other(nod)] = 1;
                if(v[vecid].l == nod)
                {
                    pos[v[vecid].r] = pos[nod] + v[vecid].d;
                }
                else
                {
                    pos[v[vecid].l] = pos[nod] - v[vecid].d;
                }
                q.push(v[vecid].other(nod));
            }
        }
    }
    cout << "Yes";
    return 0;
}