#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include<math.h>
#include<iomanip>
#include<functional>
using namespace std;

#define ll long long
using vt = ll; //ここで数値の型を変えられる
#define rep(i, n) for (vt i = 0; i < (vt)(n); i++)
#define reps(i, s, n) for(vt i = (vt) (s); i < (vt) (n); i++) 
#define all(v) v.begin(), v.end()
#define P pair<ll, ll>
const ll  MOD = 1000000007;

int main() {
	ll n, k;
	cin >> n >> k;
	vector<bitset<50>> a(n);
	rep(i, n) {
		ll x;
		cin >> x;
		bitset<50> y(x);
		a.at(i) = y;
	}
	if (k == 0) {
		ll s = 0;
		rep(i, n) s += k ^ a.at(i).to_ullong();
		cout << s;
		return 0;
	}
	bitset<50> K(k);
	ll mx = 49;
	while (!(K.test(mx))) mx--;
	bitset<50> ans1;
	for (ll i = 49; i >= 0; i--) {
		ll cnt = 0;
		rep(j, n) if (a.at(j).test(i)) cnt++;
		if (cnt < n - cnt && i <= mx) ans1.set(i);
	}
	bitset<50> ans2 = ans1;
	ans2.set(mx, 0);
	ans1.set(mx);
	vector <bitset<50>> ans;
	ans.push_back(ans2);
	for(ll i = mx; i >= 0; i--) {
		if (ans1.test(i)) {
			if (K.test(i)) {
				if (k >= ans1.to_ullong()) ans.push_back(ans1);
			}
			else {
				ans1.set(i, 0);
			}
		}
		else {
			if (K.test(i)) {
				if (k >= ans1.to_ullong()) ans.push_back(ans1);
			}
			else {
				if (k >= ans1.to_ullong()) ans.push_back(ans1);
			}
		}
	}
	ans.push_back(ans1);
	ll s = 0;
	for(auto i : ans) {
		ll t = 0;
		rep(j, n) {
			t += a.at(j).to_ullong() ^ i.to_ullong();
		}
		if (s < t) s = t;
	}
	cout << s;
	return 0;
}