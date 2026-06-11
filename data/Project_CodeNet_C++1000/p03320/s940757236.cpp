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
double cal(ll v) {

	double res = 0;
	while (v > 0)
	{
		res += v % 10;
		v /= 10;
	}
	return res;
}

void solv() {
	ll k;
	cin >> k;
	double r[10010];
	for (size_t i = 1; i <= 10000; i++)
	{
		r[i] = (i / cal(i)) ;
	}
	for (size_t i = 1; i < 10 ; i++)
	{
		cout << i << endl;
		k--;
		if (k == 0) return;
	}
	ll dig = 10;
	ll v = 9;
	while (k > 0) {
		double left = v / cal(v);
		
		int c = 0;
		int best = 0;
		double rm = 100000000000000;
		while(c < 10){
			c++;

			ll tnex = v + c * dig;
			double ca = tnex / cal(tnex);
			if (rm > ca) {
				rm = ca;
				best = c;
			}
		}
		v = v + best * dig;
		cout << v << endl;
		if (best >= 10) {
			dig *= 10;
		}
		k--;
	}
}


int main() {
	solv();

	return 0;
}
