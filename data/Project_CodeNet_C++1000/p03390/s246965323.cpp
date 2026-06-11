#include<iostream>
#include<algorithm>
#include<queue>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
typedef long long ll;
using namespace std;
ll const MAX = 1005;

ll sqr(ll x) {
	ll s, t;
	s = 0; t = 1000000001;
	while (t - s > 1) {
		ll mid = (s + t) / 2;
		if (mid*mid <= x) {
			s = mid;
		}
		else {
			t = mid;
		}
	}
	return s;
}

int main() {
	ll q;
	cin >> q;
	REP(iii, 1, q) {
		ll a, b;
		cin >> a >> b;
		ll t = a * b;
		ll x = sqr(t);
		if (x*x < t) {
			if ((x + 1)*x < t) {
				cout << 2 * x - 1 << endl;
			}
			else {
				cout << 2 * x - 2 << endl;
			}
		}
		else {
			if (a == x) {
				cout << 2 * x - 2 << endl;
			}
			else {
				cout << 2 * x - 3 << endl;
			}
		}
	}
}