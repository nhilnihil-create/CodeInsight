
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <numeric>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <tuple>

using ll = long long int;
using ul = unsigned long long int;
const ll LL_MAX (1LL<<60);
const ll MOD (1000000007);

#define rep(i,s,e) for(ll i=(s); i<(e); i++) 

using namespace std;

using T = tuple<ll,ll>;
using Graph = vector<vector<T>>;

void bfs(Graph& g, T& start, vector<ll>& dist)
{
    queue<T> que;

    dist[get<0>(start)] = 0;
    que.push(start);

    while (que.size())
    {
        T t = que.front(); que.pop();
        int v = get<0>(t);
        for (T i : g[v])
        {
            int nv = get<0>(i);
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.emplace(i); 
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    Graph g(4);
    rep(i,0,3)
    {
        ll from, to, w (0);
        cin >> from >> to;
        from--, to--;
        g[from].emplace_back(to, w);
        g[to].emplace_back(from, w);
    }

    T root;
    for (size_t i=0; i<g.size(); i++)
    { 
        if (g[i].size() == 1)
            root = T(i,0);
        break;
    }

    vector<ll> dist(g.size(), -1);
    bfs(g, root, dist);

    ll accm(0);
    for (auto i: dist)
        accm += i;

    if (accm != 0+1+2+3)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    return 0;
}
