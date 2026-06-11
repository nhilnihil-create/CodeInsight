#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

typedef pair<ll, ll> P;
vec d;
struct edge {
    ll to, cost;
};
vector<vector<edge>> G;

void dijkstra (ll s, ll V) {
    priority_queue<P, vector<P>, greater<P>> que;
    d.assign(V, inf);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        ll v = p.second;
        if (d[v] < p.first) continue;
        for (edge e : G[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll L;
    cin >> L;
    ll N = 0;
    while ((1 << N) <= L) N++;

    G.assign(N, vector<edge>());
    ll M = 2*(N-1);
    Rep (i, N-1) {
        G[i].push_back({i+1, 0});
        G[i].push_back({i+1, 1<<i});
    }

    ll tmp = L - (1 << (N-1));
    ll now = 1 << (N-1);
    for (ll i = 20; i >= 0; i--) {
        if (tmp & (1 << i)) {
            G[i].push_back({N-1, now});
            M++;
            now += 1 << i;
        }
    }

    cout << N << " " << M << "\n";
    Rep (i, N) {
        if (G[i].size() > 0) {
            for (auto nv : G[i]) {
                cout << i+1 << " " << nv.to+1 << " " << nv.cost << "\n";
            }
        }
    }
}