#pragma once
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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1000000007;
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

ll at[30][200010];
ll bt[30][200010];
ll rt[30];

void solv() {
	ll n;
	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		ll v;
		cin >> v;
		for (size_t j = 0; j < 30; j++)
		{
			at[j][i] = v % (1 << (j + 1));
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		ll v;
		cin >> v;
		for (size_t j = 0; j < 30; j++)
		{
			bt[j][i] = v % (1 << (j + 1));
		}
	}

	for (size_t i = 0; i < 30; i++)
	{
		sort(bt[i], bt[i] + n);
	}

	ll res = 0;
	for (size_t i = 0; i < 30; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			ll a = at[i][j];
			ll t = 1 << i;
			ll t2 = t * 2;
			ll t3 = t * 3;
			ll t4 = t * 4;
			int ran1 = lower_bound(bt[i],bt[i] + n,t2 - a) - lower_bound(bt[i], bt[i] + n, t - a);
			int ran2 = lower_bound(bt[i], bt[i] + n, t4 - a) - lower_bound(bt[i], bt[i] + n, t3 - a);
			rt[i] += ran1 + ran2;
		}
		if (rt[i] % 2)
			res += 1 << i;
	}
	cout << res << endl;
}


int main() {
	solv();

	return 0;
}
