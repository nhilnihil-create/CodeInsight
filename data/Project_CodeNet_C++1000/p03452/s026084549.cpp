#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define INF 1000000000000000000
#define MOD 998244353
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

const int N = 200 * 1000 + 5;
vector <pair<int, int>> v[N];
vector <bool> vis(N);
vector <int> d(N);
bool ok = true;
void dfs(int s) {
	vis[s] = true;
	for (auto g : v[s]) {
		if(!vis[g.ff]) {
			d[g.ff] = d[s] + g.ss;
			dfs(g.ff);
		}
		else {
			if(d[g.ff] != d[s] + g.ss) {
				ok = false;
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		v[x].push_back({y, w});
		v[y].push_back({x, -w});
	}
	for (int i = 1; i <= n; i++) {
		if(!vis[i]) {
			dfs(i);
		}
	}
	if(ok) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}
