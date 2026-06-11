#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <set>
#include <sstream>
using namespace std;
using ll = long long;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, pair<ll, ll>> PP;

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1 << 30;
const ll INF2 = 9e18;
const double INF3 = 9e14;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define fr first
#define sc second

ll dsum(ll s) {
	ll ss = 0, sss = s;
	while (sss) {
		ss += sss % 10;
		sss /= 10;
	}
	return ss;
}

ll Stoi(string str) {
	ll ret;
	stringstream ss;
	ss << str;
	ss >> ret;
	return ret;
}


int main() {
	ll k;
	cin >> k;
	vector<ll>ans(200000);
	ans.clear();
	map<ll, bool>mp;
	for (int i = 1;i < 10;i++) {
		ans.pb(i);
		mp[i] = 1;
	}

	for (ll j = 1;j < 13;j++) {
		for (ll i = 1;i < 1000;i++) {
			string s;
			s += to_string(i);
			for (int l = 0;l < j;l++)s += "9";
			ll p = (ll)Stoi(s);
			bool fl = 1;
			for (int m = i + 1;m < i + 20;m++) {
				string t;
				t += to_string(m);
				for (int l = 0;l < j;l++)t += "9";
				ll q = (ll)Stoi(t);
				if (p*dsum(q) > q*dsum(p)) {
					fl = 0;
				}
			}
			if (fl && !mp[p]) {
				ans.pb(p);
				mp[p] = 1;
			}
		}
	}
	sort(ALL(ans));
	for (int i = 0;i < k;i++) {
		cout << ans[i] << endl;
	}
}