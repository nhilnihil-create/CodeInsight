#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 998244353;
const ll MAX = 1000000;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

//gcd,lcm,べき,二進展開
//組み合わせ、mod計算
//最短路問題、bit、union find

///////////////////////////

ll N, M;

bool see[MAX] = {};

vector<ll> g[MAX];

vector<ll> con;

void dfs(ll u) {
	see[u] = 1;
	con.push_back(u);
	for (ll v : g[u]) {
		if (see[v] == 0) { dfs(v); }
	}
	return;
}

ll cap(vector<ll> s, vector<ll> t) {
	ll ans = 0;

	t.push_back(INF);
	for (ll x : s) {
		auto itr = lower_bound(t.begin(), t.end(),x);
		ll y = *itr;
		if (x == y) { ans++; }
	}
	return ans;
}


	
int main() {

	ll N, M;
	cin >> N >> M;

	ll p[MAX];
	repn(i, N) cin >> p[i];

	repn(i, M) {
		ll x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	ll ans = 0;

	repn(x, N) {
		if (see[x] != 0) { continue; }

		con.clear();

		dfs(x);

		vector<ll> s, t;

		for (ll y : con) {
			s.push_back(y);
			t.push_back(p[y]);
		}

		sort(s.begin(), s.end());
		sort(t.begin(), t.end());

		ans += cap(s, t);
	}

	cout << ans;



	system("PAUSE");
}