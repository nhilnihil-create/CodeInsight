#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <iomanip>
#include <bitset>
#include <set>
#include <map>
#include <stdio.h>
#include <numeric>
#include <cstring>

#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep1(i,n) for (int i = 1; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define MOD 1000000007 //10^9+7
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int INF = numeric_limits<int>::max();
const ll INFL = numeric_limits<ll>::max();


// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}

//greatest common divisor
long long gcd(ll a, ll b) 
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

//least common multiple
long long lcm(ll a, ll b)
{
    return a / gcd(a, b) * b ;
}

ll factorial(ll n) {
    ll res = 1;
    for (ll i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;
Graph G;
vector<int> res;

void dfs(int v, int p, int c) {
    res[v] = c;
    for (auto e : G[v]) {
        if (e.first == p) continue;
        if (e.second &1) dfs(e.first, v, 1-c);
        else dfs(e.first, v, c);
    }
}

int main()
{
    ll n; cin >> n;
    G.assign(n, vector<Edge>());
    for (int i = 0; i < n-1; ++i) {
        int u, v, w; cin >> u >> v >> w;
        --u, --v;
        G[u].push_back(Edge(v, w));
        G[v].push_back(Edge(u, w));
    }
    res.assign(n, 0);
    dfs(0, -1, 1);
    for (auto v : res) cout << v << endl;

    return 0;
}
