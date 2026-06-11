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


using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a,b) make_pair(a,b)
#define pbk(a) push_back(a)

int main() {
	ll n;
	cin >> n;
	ll cur = n;
	set<ll> ps;

	for(ll i = 1; i * i <= n; i++) {
		if (cur % i == 0) {
			ps.insert(i);
			ps.insert(n / i);
		}
	} 
	ll ans = 0;
	for (ll p : ps) {
		ll cur = p - 1;
		if (cur <= 1) continue;
		if (n / cur == n % cur) {
			ans += cur;
		} 
	}
	cout << ans << endl;

	
	return 0;
}