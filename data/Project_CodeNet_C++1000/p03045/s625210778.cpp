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

int p[N], r[N];

int get(int v) {
    if (v == p[v])
        return v;
    return p[v] = get(p[v]);
}

void unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v)
        return;
    if (r[u] < r[v])
        swap(u, v);
    p[v] = u;
    r[u] += r[v];
}

void solve() {
    loop1(i, N - 1) {
        p[i] = i;
        r[i] = 1;
    }
    int n, m; 
    cin >> n >> m;
    loop(i, m) {
        int u, v, usls;
        cin >> u >> v >> usls;
        unite(u, v);
    }
    set <int> s;
    loop1(i, n)
        s.insert(get(i));
    cout << s.size();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //int t; cin >> t; loop(i, t)
    solve();
    return 0;
}