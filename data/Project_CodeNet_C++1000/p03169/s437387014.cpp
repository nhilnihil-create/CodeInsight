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
    ll n;
    cin >> n;
    double m = 0;
    double mm = n;
    ll a = 0;
    ll b = 0;
    ll c = 0;
    for (int i = 0; i < n; i++) {
        ll s;
        cin >> s;
        m += s;
        if (s == 1)a++;
        else if (s == 2)b++;
        else c++;
    }
    vector<vector<vector<pair<double, double>>>>z(302, vector<vector<pair<double, double>>>(302, vector<pair<double, double>>(302)));
    z[c][b][a] = make_pair(1.0, 0.0);
    for (int i = 300; i > -1; i--) {
        for (int j = 300; j > -1; j--) {
            for (int k = 300; k > -1; k--) {
                double g = (mm - i - j - k * 1.0);
                if (j != 0)z[i][j][k].first += z[i + 1][j - 1][k].first * ((i + 1.0) / (mm-g));
                if (k != 0)z[i][j][k].first += z[i][j + 1][k - 1].first * ((j + 1.0) / (mm-g));
                z[i][j][k].first += z[i][j][k + 1].first * ((k + 1.0) / (mm-g+1.0));
                if (j != 0)z[i][j][k].second += (z[i + 1][j - 1][k].second + mm / (i+j+k+0.0)* z[i + 1][j - 1][k].first) * ((i + 1.0) / (mm - g));
                if (k != 0)z[i][j][k].second += (z[i][j + 1][k - 1].second + mm / (i + j + k+0.0) * z[i][j + 1][k - 1].first) * ((j + 1.0) / (mm - g));
                z[i][j][k].second += (z[i][j][k + 1].second + mm / (i + j + k+1.0) * z[i][j][k + 1].first) * ((k + 1.0) / (mm - g + 1.0));
            }
        }
    }
    cout << fixed << setprecision(15) << z[0][0][0].second << endl;
}