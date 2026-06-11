#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll c[] = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};
set<ll> a;
map<ll,vector<char>> dp;

bool comp(vector<char> p, vector<char> q) {// <
    if (p.size() < q.size()) return true;
    if (p.size() > q.size()) return false;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] < q[i]) return true;
        if (p[i] > q[i]) return false;
    }
    return false;
}

vector<char> solve(ll n) {
    if (n < 0) {
        vector<char> v;
        v.push_back(-1);
        return v;
    }
    if (n == 0) return vector<char>();
    if(dp.find(n) != dp.end()) return dp[n];
    vector<char> ret;
    for (auto e:a) {
        auto t = solve(n - c[e]);
        if (t.size() == 1 && t[0] < 0) continue;

        auto g = t;
        auto h = t;
        g.push_back(e);
        h.insert(h.begin(), e);
        if (comp(ret, g)) ret = g;
        if (comp(ret, h)) ret = h;
    }
    if (ret.size() == 0) {
        vector<char> v;
        v.push_back(-1);
        dp[n] = v;
    } else {
        dp[n] = ret;
    }
    return dp[n];
}

int main() {
    ll n, m, a2;
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        cin >> a2;
        a.insert(a2);
    }
    auto r = solve(n);
    for (auto e:r) cout << (int) e;
    cout << endl;
}
