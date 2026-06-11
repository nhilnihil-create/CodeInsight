#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<V>;
using VVV = vector<VV>;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
template<class T> using VE = vector<T>;
template<class T> using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
ll Abs(ll x) {
	return x < 0 ? -x : x;
}
int main() {
	int a, b, q;
	cin >> a >> b >> q;
	VL s(a), t(b);
	rep(i, a) {
		cin >> s[i];
	}
	rep(i, b) {
		cin >> t[i];
	}
	while (q--) {
		ll x;
		cin >> x;
		// それ以上の寺もしくはそれ以下の寺をまわり、そこからそれ以上の神社もしくはそれ以下の神社を回る
		// 逆もしかり、二分探索こんなにして大丈夫なのか？
		ll ans = UPPER;
		
		//初めに寺を回るほう
		auto itr1 = lower_bound(all(s), x);
		if (itr1 != s.end()) { 
			auto nitr1 = lower_bound(all(t), *itr1);
			if (nitr1 != t.end()) chmin(ans, Abs(x - *itr1) + Abs(*itr1 - *nitr1));
			if (nitr1 != t.begin()) chmin(ans, Abs(x - *itr1) + Abs(*itr1 - *--nitr1));
		}
		if (itr1 != s.begin()) {
			--itr1;
			auto nitr2 = lower_bound(all(t), *itr1);
			if (nitr2 != t.end()) chmin(ans, Abs(x - *itr1) + Abs(*itr1 - *nitr2));
			if (nitr2 != t.begin()) chmin(ans, Abs(x - *itr1) + Abs(*itr1 - *--nitr2));
		}

		//初めに神社を回るほう
		auto itr2 = lower_bound(all(t), x);
		if (itr2 != t.end()) {
			auto nitr3 = lower_bound(all(s), *itr2);
			if (nitr3 != s.end()) chmin(ans, Abs(x - *itr2) + Abs(*itr2 - *nitr3));
			if (nitr3 != s.begin()) chmin(ans, Abs(x - *itr2) + Abs(*itr2 - *--nitr3));
		}
		if (itr2 != t.begin()) {
			--itr2;
			auto nitr4 = lower_bound(all(s), *itr2);
			if (nitr4 != s.end()) chmin(ans, Abs(x - *itr2) + Abs(*itr2 - *nitr4));
			if (nitr4 != s.begin()) chmin(ans, Abs(x - *itr2) + Abs(*itr2 - *--nitr4));
		}
		cout << ans << endl;
	}
	return 0;
}