#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll a, b;
	cin >> a >> b;
	if (a == b) {
		cout << a << endl;
		return 0;
	}
	set<ll>ans;
	ll tmp = a;
	while (tmp % 4 != 0 && tmp <= b) {
		ans.insert(tmp);
		tmp++;
	}
	tmp = b;
	while (tmp % 4 != 3 && tmp >= a) {
		ans.insert(tmp);
		tmp--;
	}
	bitset<100> res(0);
	for (auto a : ans) {
		bitset<100> abit(a);
		res = res ^ abit;
	}
	ll bel = 0;
	for (int i = 0; i < 50; i++)bel += res[i] * (ll)pow(2, i);
	cout << bel << endl;
}