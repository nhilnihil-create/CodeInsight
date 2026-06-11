/*in the name of allah*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll sum;
multiset<long long> s;

void read_input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		sum -= (ll) y;
		s.insert((ll)(-x - y));
	}
}

void solve() {
	while (!s.empty()) {
		sum += *s.begin() * -1;
		s.erase(s.begin());
		if (!s.empty())
			s.erase(s.begin());
	}
	cout << sum << '\n';
}

int main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	read_input(), solve();
	return 0;
}
