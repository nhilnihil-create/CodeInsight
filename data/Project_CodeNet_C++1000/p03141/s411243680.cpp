#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P=pair<int,int>;

const int nm = 1e5;
int n, a, b;
ll ans = 0;
vector<P> v;
int main() {

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		v.emplace_back(a, b);
	}

	sort(v.begin(), v.end(), [](auto &x, auto &y) {
		return x.first + x.second > y.first + y.second;
	}
	);

	for (int i = 0; i < n; ++i)
		if (!(i & 1))
			ans += v[i].first;
		else
			ans -= v[i].second;

	cout << ans << endl;
}
