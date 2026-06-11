#include <sys/time.h>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <cctype>

using namespace std;

using ll = long long;
using P = pair<double, double>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
ll mod = 1000000007LL;

vector<ll> search(vector<ll> & u, ll x) {
	auto it = lower_bound(u.begin(), u.end(), x);
	vector<ll> ret;
	if (it != u.end()) {
		ret.push_back(*it);		
	}
	if (it != u.begin()) {
		it--;
		ret.push_back(*it);
	}
	return ret;

}


int main() {
	ll a, b, q;
	cin >> a >> b >> q;

	vector<ll> s(a);
	vector<ll> t(b);

	rep(i, a) {
		cin >> s[i];
	}
	rep(i, b) {
		cin >> t[i];
	}
	rep(i, q) {
		ll x;
		cin >> x;

		ll ans = 1e12;

		// s -> t
		vector<ll> ret_s = 	search(s, x);
		for(ll x_s : ret_s) {
			vector<ll> ret_t = search(t, x_s);
			for(ll x_t : ret_t) {
				ll cur = abs(x - x_s) + abs(x_s - x_t);
				if (cur < ans) {
					ans = cur;
				}
			} 
		} 	


		// t -> s
		vector<ll> ret_t = 	search(t, x);
		for(ll x_t : ret_t) {
			vector<ll> ret_s = search(s, x_t); 
			for(ll x_s : ret_s) {
				ll cur = abs(x - x_t) + abs(x_t - x_s);
				if (cur < ans) {
					ans = cur;
				}
			} 
		} 
		cout << ans << endl;	
	}

	return 0;
}
