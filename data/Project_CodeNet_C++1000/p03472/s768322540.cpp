#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	ll n, h;
	cin >> n >> h;
	ll maxa = 0;
	priority_queue<ll> bs;
	for (int i=0; i<n; i++) {
		ll a, b;
		cin >> a >> b;
		if (a > maxa) maxa = a;
		bs.push(b);
	}
	ll ret = 0;
	while (!bs.empty()) {
		if (bs.top() < maxa) {
			bs.pop();
			continue;
		}
		h -= bs.top();
		bs.pop();
		ret++;
		if (h <= 0) {
			cout << ret << endl;
			return 0;
		}
	}
	cout << ret + (h + maxa - 1)/maxa << endl;
	
	return 0;
}