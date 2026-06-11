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
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) REP(sz, vec.size()) cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    string s; cin >> s;
    vvll edges(n);
    REP(i, m) {
        ll a, b; cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }

    vll stack;
    V< map<char, ll> > topo(n);
    REP(i, n) {
        map<char, ll> sc = {{'A', 0}, {'B', 0}};
        for (ll e: edges[i]) {
            if (s[e] == 'A') sc['A']++;
            else sc['B']++;
        }
        if (sc['A'] == 0 || sc['B'] == 0) stack.emplace_back(i);
        topo[i] = sc;
    }

    vll poped(n, 0);
    while (!stack.empty()) {
        ll i = *(--stack.end());
        stack.pop_back();
        if (poped[i] == 1) continue;
        poped[i] = 1;
        for (ll e: edges[i]) {
            topo[e][s[i]]--;
            if (topo[e][s[i]] == 0) stack.emplace_back(e);
        }
    }

    REP(i, n) {
        if (poped[i] == 0) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
