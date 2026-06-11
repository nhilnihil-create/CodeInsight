#pragma once
#include <stdio.h>
#include <sstream>
#include <string>
#include <string.h>
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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define bit(x,v) ((ll)x << v)

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
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
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

// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)
vector<vector<int> > calcNext(const string& S) {
	int n = (int)S.size();
	vector<vector<int> > res(n + 1, vector<int>(26, n));
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < 26; ++j) res[i][j] = res[i + 1][j];
		res[i][S[i] - 'a'] = i;
	}
	return res;
}
// mod 1000000007 の世界で a += b する関数
void add(long long& a, long long b) {
	a += b;
	if (a >= MOD) a -= MOD;
}
struct edge {
	int to;
	ll cost;
	edge(int to,ll cost) : to(to),cost(cost){}

};
vector<edge> es[100010];
int x[100010], y[100010];
ll d[100010];
void dija(int s) {
	fill(d, d + 100010, INF * INF);
	d[s] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> q;
	q.push(pll(0, s));
	while (!q.empty())
	{
		pll p = q.top();
		q.pop();
		if (p.first > d[p.second]) continue;
		for (auto it : es[p.second]) {
			if (d[it.to] > d[p.second] + it.cost) {
				d[it.to] = d[p.second] + it.cost;
				q.push(pll(d[it.to],it.to));
			}
		}
	}
}
int t[105];
int v[105];
int n;

bool check(double nv,double tm) {

	double st = 0;
	for (size_t i = 0; i <= n; i++)
	{
		double bef = st;
		st += t[i];

		if (tm > st) continue;
		double vp = (double)v[i];
		if (nv <= vp) continue;
		double inter = bef - tm;
		if (inter < 0) return false;
		if (nv - vp > inter) return false;
	}
	return true;
}
double one = 1;
double two = 2;
const double fast = (one / two) * (0.5 * 0.5);
double calc(double f, double t) {

	
	if (f < t) {
		return (f * 0.5) + fast;
	}
	else if (f > t) {
		return (f * 0.5) - fast;
	}
	else return (f * 0.5);

}

void solv() {
	cin >> n;
	t[n] = 0;
	v[n] = 0;
	for (size_t i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	for (size_t i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	double now = 0;
	double res = 0;
	double time = 0;
	double ls = 0;
	for (int i = 0; i < n; i++)
	{
		for (double j = 0; j < t[i]; j += 0.5)
		{

			if (check(now + 0.5,time + 0.5)) {
				res += calc(now, now + 0.5);
				now += 0.5;
			}
			else if (check(now, time + 0.5)) {
				res += calc(now, now);
			}
			else {
				double pt = calc(now, now - 0.5);
				res += pt;
				ls += pt;
				now -= 0.5;
			}
			time += 0.5;
		}
	}
	if (now == 0.5) {
		res += calc(now, 0);
	}
	cout << setprecision(10) << res << endl;
}

int main() {
	//COMinit();
	solv();

	return 0;
}
