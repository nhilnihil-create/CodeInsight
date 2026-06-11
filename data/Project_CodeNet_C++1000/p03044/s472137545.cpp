#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <numeric>
#include <ctime>
#include <complex>
#include <bitset>
#include <random>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;

//#define int ll
#define double ld
#define loop(i, n) for(int i = 0; i < (int)n; ++i)
#define loop1(i, n) for(int i = 1; i <= (int)n; ++i)
#define F first
#define S second
#define pb push_back
#define pi pair <int, int>
#define all(x) begin(x), end(x)
#define ti tuple <int, int, int>
#define Point Vect
#define mkt make_tuple
#define no {cout << -1; return;}

const int N = 1e5 + 7;

vector <pi> g[N];
int col[N];

void dfs(int v, int p, int c) {
    col[v] = c;
    for (pi u : g[v])
        if (u.F != p)
            dfs(u.F, v, (u.S & 1 ? 3 - c : c));
}

void solve() {
    int n; cin >> n;
    loop(i, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({ v, w });
        g[v].pb({ u, w });
    }
    dfs(1, 1, 1);
    loop1(i, n)
        cout << col[i] - 1 << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}