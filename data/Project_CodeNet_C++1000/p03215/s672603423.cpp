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
const int INF = 1e9 + 7;
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
	int N, K; cin >> N >> K;
	int a[1010];
	REP(i, N)cin >> a[i];
	vector<ll>sum;
	sum.push_back(0);
	REP(i, N) {
		sum.push_back(sum[i] + a[i]);
	}
	vector<ll>V;
	for (int i = 0; i < N; ++i) {
		for (int j = i+1; j <= N; ++j) {
			V.push_back(sum[j] - sum[i]);
		}
	}
	sort(V.begin(), V.end(),greater<ll>());
	int n = V.size();
	vector<int>ok(n, 1);
	ll ans = 0;
	for (int i = 60; i >= 0; --i) {
		ll msk = 1LL << i;
		int cnt = 0;
		REP(j, n)if ((V[j] & msk) && ok[j])cnt++;
		if (K <= cnt) {
			ans += msk;
			REP(j, n)if (!(V[j] & msk) && ok[j])ok[j] = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
