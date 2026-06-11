#include <bits/stdc++.h>
using namespace std;

using i64 = long long;


int main() {
#ifdef HOME
	freopen("agc.in", "r", stdin);
	freopen("agc.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	map<pair<string, string>, int> mp;
	string str, lf, rt;
	i64 ant;
	int n;

	cin >> n >> str;
	lf = str.substr(0, n);
	rt = str.substr(n, 2 * n);

	for (int msk = 0; msk < (1 << n); msk++) {
		string red, blue;
		for (int lg = 0; lg < n; ++lg)
			(((1 << lg) & msk) ? red : blue).push_back(rt[lg]);
		mp[make_pair(red, blue)]+= 1; }

	ant = 0;
	reverse(begin(lf), end(lf));
	for (int msk = 0; msk < (1 << n); ++msk) {
		string red, blue;
		for (int lg = 0; lg < n; ++lg)
			(((1 << lg) & msk) ? red : blue).push_back(lf[lg]);
		ant+= mp[make_pair(blue, red)]; }

	cout << ant << endl;

	return 0; }

