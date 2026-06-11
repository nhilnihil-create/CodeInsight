#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
#include <ctime>
#include <tuple>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

/*
using PAIR = pair<string, int>;
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long ll;

#define fi first
#define se second
#define rep(i, n) for (ll i = 0; i < n; i++)
#define debugA() cerr << "AAAAA" << endl
#define debug_() cerr << "-------------" << endl
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v)                   \
    cout << #v << endl;                \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << endl;
#define debug_vec2(v)                         \
    cout << #v << endl;                       \
    for (int i = 0; i < v.size(); i++)        \
    {                                         \
        for (int j = 0; j < v[i].size(); j++) \
        {                                     \
            cout << v[i][j] << " ";           \
        }                                     \
        cout << endl;                         \
    }

using Graph = vector<vector<int>>;
using P = pair<int, int>;
using P1 = pair<int, pair<int, int>>; // クラスカル法とかで、{cost, {from, to}}的に使う。
const ll INF = 1001001001001001001;
const double pi = acos(-1);

int main()
{
    int n;
    cin >> n;
    vector<vector<P>> G(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        G[x].push_back({y, w});
        G[y].push_back({x, w});
    }

    vector<ll> dist(n, -1);
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        for (auto nv : G[v])
        {
            int x = nv.fi;
            int w = nv.se;
            if (dist[x] == -1)
            {
                dist[x] = dist[v] + w;
                que.push(x);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] % 2 << endl;
    }

    return 0;
}
