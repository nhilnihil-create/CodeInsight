#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>
#include <iomanip>

#define vec vector

using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;
using vvl = vector<vl>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using ld = long double;

int n;
vvi adj;
ll mod = 1e9 + 7;

pll doofus(int node, int parent)
{
    pll ways = {1, 1};
    if (adj[node].size() == 1)
        return {1, 1};
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (adj[node][i] != parent)
        {
            pll w = doofus(adj[node][i], node);
            ways.first = (ways.first * ((w.first + w.second) % mod)) % mod;
            ways.second = (ways.second * w.first) % mod;
        }
    }
    return ways;
}

int main()
{
    cin >> n;
    adj = vvi(n + 1, vi());
    for (int i = 0; i < n - 1; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    adj[1].push_back(0);
    pll w = doofus(1, 0);
    cout << (w.first + w.second) % mod;
    return 0;
}