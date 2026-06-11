#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <map>
#include <queue>
#include <set>
#include <complex>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>
#include <cmath>
#include <stdio.h>
#include <functional>

using namespace std;
using ll = long long;
using ld = double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>; //(x, y, dx, dy)
const ll INF = 1e17;
const ld eps = 1e-10;
const ll MOD = 1e9 + 7;

const double pi = acos(-1.0);

vector<pair<char, char>> v;
string s;

int check(int x) {
	for (int i = 0;i < v.size();i++) {
		char c, move;
		tie(c, move) = v[i];
		if (s[x] == c && move == 'L')
			x--;
		else if (s[x] == c && move == 'R')
			x++;
		if (x < 0 || x >= s.size())
			break;
	}
	if (x < 0)
		return -1;
	else if (x >= s.size())
		return 1;
	else
		return 0;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll N, Q;
	cin >> N >> Q;
	cin >> s;
	v.assign(Q, P('a', 'a'));
	for (int q = 0;q < Q;q++) {
		char a, b;
		cin >> a >> b;
		v[q] = make_pair(a, b);
	}
	ll l_l = -1, l_r = N, r_l = -1, r_r = N;
	while (l_r - l_l > 1) {
		ll m = (l_l + l_r) / 2;
		if (check(m) == -1)
			l_l = m;
		else
			l_r = m;
	}
	while (r_r - r_l > 1) {
		ll m = (r_l + r_r) / 2;
		if (check(m) == 1)
			r_r = m;
		else
			r_l = m;
	}
	cout << N - (l_r + (N - r_r)) << endl;
	return 0;
}
