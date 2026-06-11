#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <utility>
#include <functional>
#include <deque>
#include <cctype>
#include <stack>
#include <bitset>
#include <set>

using namespace std;
using ll = long long;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

const ll MOD = 1e9 + 7;
const ll INF = 1 << 30;
const ll INF2 = 9e18;
const double INF3 = 9e14;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define fr first
#define sc second

struct edge { ll to, cost; };
vector<edge>v[100010];
ll d[100010];

int main() {
	ll k;
	cin >> k;
	for (int i = 0;i < k;i++) {
		v[i].pb(edge{ (i + 1) % k,1 });
		v[i].pb(edge{ (i * 10) % k,0 });
	}
	priority_queue < P, vector<P>, greater<P>>pq;
	for (int i = 0;i < k;i++)d[i] = INF;
	d[1] = 1;
	pq.push(P(1, 1));
	while (!pq.empty()) {
		P a = pq.top();
		pq.pop();
		ll i = a.second;
		if (d[i] < a.first)continue;
		for (auto u : v[i]) {
			edge e = u;
			if (d[e.to] <= d[i] + e.cost)continue;
			d[e.to] = d[i] + e.cost;
			pq.push(P{ d[e.to], e.to });
		}
	}
	cout << d[0] << endl;
	}
