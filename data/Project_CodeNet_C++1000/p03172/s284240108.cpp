#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <functional>
#include <ctime>
#include <cmath>
#include <limits>
#include <numeric>
#include <type_traits>
#include <iomanip>
#include <float.h>
#include <math.h>
using namespace std;
using ll = long long;
unsigned euclidean_gcd(unsigned a, unsigned b) {
    if (a < b) return euclidean_gcd(b, a);
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

ll ll_gcd(ll a, ll b) {
    if (a < b) return ll_gcd(b, a);
    ll r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

class UnionFind {
public:
    vector <ll> par;
    vector <ll> siz;
    UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    ll root(ll x) {
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }

    ll size(ll x) {
        return siz[root(x)];
    }
};

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

vector<int> tpsort(vector<vector<int>>& G) {
    int V = G.size();
    vector<int> sorted_vertices;
    queue<int> que;
    vector<int> indegree(V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            indegree[G[i][j]]++;
        }
    }
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }
    while (que.empty() == false) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v][i];
            indegree[u] -= 1;
            if (indegree[u] == 0) que.push(u);
        }
        sorted_vertices.push_back(v);
    }
    return sorted_vertices;
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> z(n);
    for (int i = 0; i < n; i++) {
        cin >> z[i];
    }
    vector<ll> dp(k+1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<ll> x(k + 2);
        for (int j = 0; j < k+1; j++){
            x[j + 1] = dp[j] + x[j];
            x[j + 1] %= 1000000007;
        }
        for (int j = 0; j < k+1; j++) {
            dp[j] = x[min(j+1, k + 1)] - x[max(j-z[i],0)]+1000000007;
            dp[j] %= 1000000007;
        }
    }
    cout << dp[k] << endl;
}