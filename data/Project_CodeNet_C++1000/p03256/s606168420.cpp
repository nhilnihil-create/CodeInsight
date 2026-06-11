#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

const double PI = 3.1415926535897932384626433832795;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int n, m;
string s;
const int MAX = 200000;
vector<vector<int>> edges(MAX);
vector<int> numA(MAX), numB(MAX);
vector<bool> deleted(MAX);

void del(int i) {
	if (deleted[i]) {
		return;
	}

	deleted[i] = true;
	for (auto j : edges[i]) {
		if (deleted[j]) {
			continue;
		}

		(s[i] == 'A' ? numA[j] : numB[j])--;

		if (numA[j] == 0 || numB[j] == 0) {
			del(j);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;

		edges[a].emplace_back(b);
		edges[b].emplace_back(a);
		(s[b] == 'A' ? numA[a] : numB[a])++;
		(s[a] == 'A' ? numA[b] : numB[b])++;
	}

	for (int i = 0; i < n; i++) {
		if (numA[i] == 0 || numB[i] == 0) {
			del(i);
		}
	}

	for (int i = 0; i < n; i++) {
		if (!deleted[i]) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
	return 0;
}
