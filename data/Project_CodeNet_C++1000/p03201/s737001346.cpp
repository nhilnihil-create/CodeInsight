#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const double pi = acos(-1);
#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)
#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME
#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	REP(i, v.size()) { if (i)os << " "; os << v[i]; }return os;
}
template<typename T> ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
	REP(i, v.size()) { if (i)os << endl; os << v[i]; }return os;
}

const ll INF = LLONG_MAX;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

#define int long long

inline void my_io() {

	std::ios::sync_with_stdio(false);

	std::cin.tie(0);

	cout << fixed << setprecision(16);

	//cout << setprecision(10) << scientific << ans << endl;
}

signed main() {
	ll n, a;
	string s, ss;

	cin >> n;

	multiset<ll> ms;

	REP(i, n) {
		cin >> a;
		ms.insert(a);
	}

	ll ans = 0;
	bool flag;

	while (ms.size() > 1) {
		auto itr = ms.end();
		a = *(--itr);
		if (a == 1) {
			ans++;
			itr = ms.erase(itr);
			ms.erase(--itr);
			continue;
		}
		/*
		if (a % 2) {
			s = "1";
		}
		else {
			s = "0";
		}
		a = (a >> 1);
		*/
		bitset<32> bs(a);
		ll start = 0;
		REP(i, 32) {
			if (bs[i]) {
				start = i;
				break;
			}
		}
		flag = true;
		s = "";
		ss = "";
		RFOR(i, start + 1, 32) {
			if (flag) {
				if (bs[i]) {
					flag = false;
				}
			}
			if (!flag) {
				if (bs[i]) {
					ss = ss + "0";
				}
				else {
					ss = ss + "1";
				}
			}
		}
		REP(i, start + 1) {
			if (bs[i]) {
				s = "1" + s;
			}
			else {
				s = "0" + s;
			}
		}
		s = ss + s;
		if (s[s.size() - 1] == '0' && bs.count() == 1) {
			if (*(--itr) == a) {
				ans++;
				itr = ms.erase(itr);
				ms.erase(itr);
			}
			else {
				ms.erase(++itr);
			}
		}
		else if (stoi(s, 0, 2) == 0) {
			auto itr2 = ms.find(2);
			if (itr2 != ms.end()) {
				ans++;
				ms.erase(itr);
				ms.erase(itr2);
			}
			else {
				ms.erase(itr);
			}
		}
		else {
			auto itr2 = ms.find(stoi(s, 0, 2));
			if (itr2 != ms.end()) {
				ans++;
				ms.erase(itr);
				ms.erase(itr2);
			}
			else {
				ms.erase(itr);
			}
		}
		/*
		for (auto it = ms.begin(); it != ms.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
		//*/
	}

	cout << ans << endl;
}