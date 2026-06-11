#include <stdio.h>
#include <string.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
#include <limits>
#include <iomanip>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1000000007;

const int MAX = 210000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int pr[100010];
void uini(int n) {
	for (size_t i = 0; i <= n; i++)
	{
		pr[i] = i;
	}
}

int parent(int x) {
	if (x == pr[x]) return x;
	return pr[x] = parent(pr[x]);
}

bool unit(int x, int y) {
	int px = parent(x);
	int py = parent(y);

	if (px == py) return false;
	if (px < py) {
		pr[py] = px;
	}
	else {
		pr[px] = py;
	}
	return true;
}
struct edge {
	int to;
	ll cost;
	edge(int _to, ll _cost) : to(_to), cost(_cost) {}
};

void solv() {
	ll n;
	cin >> n;
	ll a[200010];
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (size_t i = 1; i < n; i++)
	{
		a[i] = a[i - 1] + a[i];
	}

	int le = 0;
	int ri = 2;
	ll res = INF;
	for (size_t i = 1; i < n - 1; i++)
	{
		ll p, q, r, s;
		p = a[le];
		q = a[i] - a[le];
		if (ri == i) ri++;
		r = a[ri] - a[i];
		s = a[n - 1] - a[ri];

		ll left = abs(a[le] - (a[i] - a[le]));

		for (size_t j = le + 1; j  < i; j++)
		{
			ll tl = abs(a[j] - (a[i] - a[j]));
			if (left < tl) break;
			left = tl;
			le = j;
			p = a[j];
			q = a[i] - a[j];
		}

		ll right = abs((a[ri] - a[i]) - (a[n - 1] - a[ri]));

		for (size_t j = ri + 1; j < n; j++)
		{
			ll tl = abs((a[j] - a[i]) - (a[n - 1] - a[j]));
			if (right < tl) break;
			right = tl;
			ri = j;
			r = (a[j] - a[i]);
			s = (a[n - 1] - a[j]);
		}
		res = min(res, max(max(p, q), max(r, s)) - min(min(p, q), min(r, s)));
	}
	cout << res << endl;
}

int main() {
	//COMinit();
	solv();

	return 0;
}
	