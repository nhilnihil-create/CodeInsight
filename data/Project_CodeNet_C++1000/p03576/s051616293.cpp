#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#define _USE_MATH_DEFINES
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0,1,0,-1 };
const ll dy[4] = { -1, 0, 1,0 };
const ll INF = 1e9 + 7;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
double mysqrt(double x) {
	double l = 0, r = x;
	for (int i = 0; i < 64; ++i) {
		double m = (l + r) / 2.0;
		if (m*m < x)l = m;
		else r = m;
	}
	return l;
}
///////////////////////////////////////


int main() {
	ll N, K; cin >> N >> K;
	vector<ll>x;
	vector<ll>y;
	REP(i, N) {
		ll a, b; cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}
	ll ans = 1e18*5;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N ; ++k) {
				for (int l = 0; l < N; ++l) {
					if (i == j || k == l)continue;
					if (x[i] > x[j])continue;
					if (y[k] > y[l])continue;
					int cnt = 0;
					for (int m = 0; m < N; ++m) {
						if (x[i] <= x[m] && x[m] <= x[j] && y[k] <= y[m] && y[m] <= y[l]) {
							cnt++;
						}
					}
					if (cnt >= K) {
						ll key = (x[j] - x[i])*(y[l] - y[k]);
						if (key > 0) {
							ans = min(ans, key);
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}