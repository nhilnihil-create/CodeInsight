#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>
#include <cmath>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SZ = 1e5 + 100;
ll n;
vector<vector<ll>> gr;
vector<pair<ll, ll>> vec;

ll sub[SZ], dp[SZ];
map<ll, ll> m;

int main()
{
	fastInp;

	cin >> n;

	vec.resize(n);
	for (auto &cur : vec) cin >> cur.first;
	for (int i = 0; i < n; i++) {
		sub[i] = 1;
		vec[i].second = i;
		m[vec[i].first] = vec[i].second;
	}

	sort(vec.rbegin(), vec.rend());

	vector<pair<ll, ll>> edges;
	for (int i = 0; i < vec.size() - 1; i++) {
		ll par = vec[i].first + sub[vec[i].second] - (n - sub[vec[i].second]);
		if (m.find(par) == m.end() || m[par] == vec[i].second) {
			cout << "-1";
			return 0;
		}

		sub[m[par]] += sub[vec[i].second];
		dp[m[par]] += sub[vec[i].second] + dp[vec[i].second];
		edges.push_back({ vec[i].second, m[par] });
	}

	if (dp[vec.back().second] != vec.back().first) {
		cout << "-1";
		return 0;
	}
	for (auto cur : edges) {
		cout << cur.first + 1 << " " << cur.second + 1 << "\n";
	}

	return 0;
}