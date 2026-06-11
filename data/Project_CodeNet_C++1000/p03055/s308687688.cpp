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
const ll MOD = 998244353;
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

ll diam(vector<vector<edge>> g, ll N) {

	queue<ll> q;
	vector<ll> dis(N + 1, -1);
	dis[1] = 0;
	q.push(1);

	while (!q.empty()) {
		ll v = q.front();
		q.pop();

		for (edge e : g[v]) {
			if (dis[e.to] != -1) { continue; }
			q.push(e.to);
			dis[e.to] = dis[v] + e.d;
		}
	}

	ll maxdis = -INF;
	ll maxid = 1;
	repn(i, N) {
		if (maxdis < dis[i]) {
			maxdis = dis[i];
			maxid = i;
		}
	}

	vector<ll> dis2(N + 1, -1);
	dis2[maxid] = 0;
	q.push(maxid);

	while (!q.empty()) {
		ll v = q.front();
		q.pop();

		for (edge e : g[v]) {
			if (dis2[e.to] != -1) { continue; }
			q.push(e.to);
			dis2[e.to] = dis2[v] + e.d;
		}
	}

	ll ret = -INF;
	repn(i, N) {
		ret = max(ret, dis2[i]);
	}

	return ret;

}


int main() {

	ll N;
	cin >> N;

	vector <vector<edge>> g(N + 1);

	repn(i, N - 1) {
		ll a, b;
		cin >> a>> b;
		g[a].push_back({ i,a,b,1 });
		g[b].push_back({ i,b,a,1 });
	}

	ll d = diam(g, N);

	if (d % 3 == 1) { cout << "Second"; }
	else { cout << "First"; }
	
	
	system("PAUSE");
}
