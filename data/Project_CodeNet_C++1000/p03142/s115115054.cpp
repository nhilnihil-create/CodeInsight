#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;

//typedef modint998244353 mint;

const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

const ll MAX = 1e9 + 5;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < n + m - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;

		g[a].emplace_back(b);
	}

	vector<int> inDegree(n);

	for (int i = 0; i < n; i++) {
		for (int v : g[i]) {
			inDegree[v]++;
		}
	}

	int r = -1;
	for (int i = 0; i < n; i++) {
		if (inDegree[i]==0) {
			r = i;
		}
	}

	vector<int> p(n);
	p[r] = -1;
	queue<int> q;
	

	q.push(r);
	while (!q.empty()) {
		int v = q.front();
		//cout << v << endl;
		q.pop();
		
		

		for (int u : g[v]) {
			
			inDegree[u]--;
			if (inDegree[u] != 0) {
				continue;
			}
			p[u] = v;
			
			q.push(u);
		}
		
	}

	for (int pi: p) {
		cout << pi + 1 << endl;
	}
	
}