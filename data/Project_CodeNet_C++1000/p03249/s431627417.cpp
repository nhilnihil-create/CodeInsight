#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

int n, rt;
pair<long long, int> d[100009];
set<pair<long long, int> > st;
vector<pair<int, int> > vec;
map<long long, int> mp;
vector<int> vec2[100009];

long long fun(int c)
{
	if (d[c].se == 1) return 1;
	long long retval = 0;
	for (int i = 0; i < (int)vec2[c].size(); i++) {
		retval += fun(vec2[c][i]);
	}
	if (c == rt) return retval;
	else return retval + d[c].se;
}

bool gun(int c, long long cd)
{
	if (cd != d[c].fi) return false;
	for (int i = 0; i < (int)vec2[c].size(); i++) {
		if (!gun(vec2[c][i], d[c].fi + n - 2*d[vec2[c][i]].se)) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d[i].fi;
		d[i].se = 1;
		st.insert({ -d[i].fi, i });
		mp[d[i].fi] = i;
	}
	while (1) {
		auto x = st.begin();
		int cur = (*x).se;
		st.erase(x);
		long long tmp = d[cur].fi - n + 2 * d[cur].se;
		if (mp.count(tmp) == 0) {
			cout << -1 << E;
			return 0;
		}
		int to = mp[tmp];
		if (to == cur) {
			cout << -1 << E;
			return 0;
		}
		d[to].se += d[cur].se;
		vec.pb(make_pair(to, cur));
		if (vec.size() == n - 1) {
			x = st.begin();
			rt = (*x).se;
			break;
		}
	}
	for (int i = 0; i < (int)vec.size(); i++) {
		vec2[vec[i].fi].pb(vec[i].se);
	}
	if (!gun(rt, fun(rt))) {
		cout << -1 << E;
	}
	else {
		for (int i = 0; i < n - 1; i++) {
			cout << vec[i].fi << " " << vec[i].se << E;
		}
	}
	//system("pause");
	return 0;
}