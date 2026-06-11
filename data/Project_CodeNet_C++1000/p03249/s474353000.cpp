#include <bits/stdc++.h>
#define Stop { cout << "-1\n"; return 0; }

using namespace std;

typedef long long ll;
const int Nmax = 1e5 + 5;

map<ll, int> mp;
vector<int> v[Nmax];
ll d[Nmax], Sum;
int t[Nmax], w[Nmax], level[Nmax];
int n, i, node, dad, root;

void dfs(int node)
{
    for(auto it : v[node])
    {
        level[it] = level[node] + 1;
        dfs(it);
        w[node] += w[it];
    }
    Sum += level[node];
}

bool verif()
{
    int i;
    for(i=1; i<=n; ++i)
    {
        w[i] = 1;
        v[t[i]].push_back(i);
    }

    dfs(root);

    if(Sum != d[root]) return 0;

    for(i=1; i<=n; ++i)
        if(i != root)
            if(d[i] != d[t[i]] + n - 2 * w[i]) return 0;
    return 1;
}

int main()
{
 ///   freopen("input", "r", stdin);
    cin.sync_with_stdio(false);

    cin >> n;
    for(i=1; i<=n; ++i) cin >> d[i], mp[d[i]] = i, w[i] = 1;

    root = mp.begin() -> second;

    for(auto it = mp.rbegin(); it != mp.rend(); ++it)
    {
        node = it->second;
        dad = mp[ d[node] - n + 2 * w[node] ];

        if(node == root) dad = 0;
            else if(!dad) Stop;
        if(dad == node) Stop;

        t[node] = dad;
        w[dad] += w[node];
    }

    if(!verif()) Stop;

    for(i=1; i<=n; ++i)
        if(t[i]) cout << t[i] << ' ' << i << '\n';
    return 0;
}
