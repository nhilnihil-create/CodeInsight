#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto x : v) cerr << x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int i = 0; i < (n); ++i) cerr << a[i] << ", "; cerr << endl
typedef long long ll;
typedef long double ld;
ll num[155];
int main() {
	ll mx = 1e15;
	int K;
	scanf("%d", &K);
	vector<ll> v;
	for (int x = 1; x <= 135; ++x) {
		ll y = x;
		while (y <= mx) {
			v.push_back(y);
			y = y * 10 + 9;
		}
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (int i = 0; i < v.size(); ++i) {
		string s = to_string(v[i]);
		int d = 0;
		for (char c : s) d += c - '0';
		ll add = 1;
		while (!s.empty()) {
			if (s.back() == '9') add *= 10;
			else break;
			s.pop_back();
		}
		bool bad = (v[i] + add) * d < v[i] * (d + 1);
		if (K && !bad) {
			printf("%lld\n", v[i]);
			--K;
		}
	}
}
