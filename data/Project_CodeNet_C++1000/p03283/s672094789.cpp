#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>
// #include <atcoder/all>

#define int long long

struct edge {
    int to;
    int cost;
};

using namespace std;
// using namespace atcoder;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
using qi = queue<int>;
using P = pair<int, int>;
using graph = vector<vector<edge>>;
// using graph = vector<vector<int>>;
// using mint = modint1000000007;


#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define delim(i, n) cout << (i == n-1 ? "\n" : " ")
#define print1(v) cout << fixed << setprecision(10) << v << "\n"
#define print2(v1, v2) cout << fixed << setprecision(10) << v1 << " " << v2 << "\n"
#define print3(v1, v2, v3) cout << fixed << setprecision(10) << v1 << " " << v2 << " " << v3 << "\n"
#define printvi(v, n) REP(iiii, n) { cout << v[iiii]; delim(iiii, n); }
#define printvii(v, h, w) REP(iiiii, h) { printvi(v[iiiii], w); }

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int inf = 1LL << 60;
// const int inf = 100000000;
const int mod = 1000000007;

const int maxn = 500+1;
int n, m, k;
vii train(maxn, vi(maxn));

vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};

signed main () {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    REP(i, m) {
        int l, r; cin >> l >> r;
        train[l][r]++;
    }
    FOR(i, 1, n+1) {
        FOR(j, 1, n+1) {
            train[i][j] += train[i][j-1] + train[i-1][j] - train[i-1][j-1];
        }
    }
    REP(i, k) {
        int p, q; cin >> p >> q;
        p--;
        int ret = train[q][q] - train[p][q] - train[q][p] + train[p][p];
        print1(ret);
    }
}