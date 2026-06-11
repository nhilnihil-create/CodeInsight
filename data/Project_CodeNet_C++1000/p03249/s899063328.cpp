#pragma GCC optimize("Ofast")
/*#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <random>
#include <iomanip>
#include <bitset>
                      
using namespace std;
                      
template<typename T> void uin(T &a, T b) {
    if (b < a) {
        a = b;
    }
}
                      
template<typename T> void uax(T &a, T b) {
    if (b > a) {
        a = b;
    }
}

#define int long long
#define ghost signed
#define left left228
#define right right228
#define prev prev228
#define list list228

const int N = 100 * 1000 + 228;

int n;
int d[N], sz[N];
map<int, int> pos; 
vector<int> g[N];

bool cmp(int i, int j) {
	return d[i] > d[j];
}

int D[N], S[N];
int sumd = 0;
bool OK = 1;

void jfs(int v, int par = -1) {
	S[v] = 1;
	for (int to : g[v]) {
		if (to == par) continue;
		jfs(to, v);
		S[v] += S[to];
	}
}

void bfs(int a) {
	for (int i = 1; i <= n; ++i) D[i] = n * 100;
	D[a] = 0;
	vector<int> q;
	q.push_back(a);
	for (int i = 0; i < (int)q.size(); ++i) {
		int v = q[i];
		for (int to : g[v]) {
			if (D[v] + 1 < D[to]) {
				D[to] = D[v] + 1;
				q.push_back(to);
			}
		}
	}
	for (int i = 1; i <= n; ++i) sumd += D[i];
	jfs(1);
}

void dfs(int v, int par = -1) {
	if (v != 1) {
		sumd -= S[v];
		sumd += (n - S[v]);
	}
	if (sumd != d[v]) OK = 0;
	for (int to : g[v]){
		if (to == par) continue;
		dfs(to, v);
	}
	if (v != 1) {
		sumd += S[v];
		sumd -= (n - S[v]);
	}
}

bool check() {
	bfs(1);
	dfs(1);
	return OK;
}

ghost main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
		pos[d[i]] = i;
	}
	vector<int> order;
	for (int i = 1; i <= n; ++i) order.push_back(i);
	for (int i = 1; i <= n; ++i) sz[i] = 1;
	sort(order.begin(), order.end(), cmp);
	vector< pair<int, int> > e;
	int last = order.back();
	for (int v : order) {
		if (v == last) break;
		int nd = d[v] + 2 * sz[v] - n;
		if (nd <= v) {
			cout << -1 << endl;
			return 0;
		}
		int par = pos[nd];
		if (par == 0) {
			cout << -1 << endl;
			return 0;
		}
		e.push_back(make_pair(par, v));
		g[par].push_back(v);
		g[v].push_back(par);
		sz[par] += sz[v];
	}
	if (!check()) {
		cout << -1 << endl;
		return 0;
	}
	for (auto p : e) cout << p.first << " " << p.second << '\n';
	return 0;
} // kek ;



