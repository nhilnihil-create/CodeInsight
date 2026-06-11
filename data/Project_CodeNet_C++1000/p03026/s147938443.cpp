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

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) *b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};


///////////////////////////




int main() {

	ll N;
	cin >> N;

	vector<vector<ll>> t(N + 1);

	repn(i, N - 1) {
		ll a, b;
		cin >> a >> b;
		t[a].push_back(b);
		t[b].push_back(a);
	}

	vector<ll> c(N + 1);
	repn(i, N) cin >> c[i];
	sort(++c.begin(), c.end(), greater<ll>());

	queue<ll> q;
	vector<ll> ans(N + 1, -1);

	ll pos = 1;
	q.push(1);
	ans[1] = c[pos];

	while (!q.empty()) {
		ll v = q.front();
		q.pop();

		for (ll w : t[v]) {
			if (ans[w] != -1) { continue; }
			pos++;
			q.push(w);
			ans[w] = c[pos];
		}
	}

	ll sum = 0;
	for (ll i = 2; i <= N; i++) { sum += c[i]; }

	cout << sum << endl;
	repn(i, N) cout << ans[i] << " ";


	system("PAUSE");
}
