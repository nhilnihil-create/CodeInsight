// 見せてやるぜ、奇跡ってやつをよぉ……
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>
#include <cassert>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}
#define DEBUG_VLL(vec) REP(i, vec.size()) cerr<<vec[i]<<(i==vec.size()-1?'\n':' ');

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

vvll edges;
vll col;

bool isBipartite() {
    col[0] = 0;
    queue<ll> que; que.push(0);
    while (!que.empty()) {
        ll q = que.front(); que.pop();
        for (ll e: edges[q]) {
            if (col[e] == -1) {
                col[e] = col[q]^1;
                que.push(e);
            } else {
                if (col[e] == col[q]) return false;
            }
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    edges.resize(n);
    col.resize(n, -1);
    REP(i, m) {
        ll a, b; cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    if (isBipartite()) {
        ll bc=0, wc=0;
        REP(i, n) if (col[i]==0) wc++; else bc++;
        cout << bc * wc - m << '\n';
    } else {
        cout << n * (n-1) / 2 - m << '\n';
    }
    return 0;
}
