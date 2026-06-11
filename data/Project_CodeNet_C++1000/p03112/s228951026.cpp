#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long INF = (long long)1e15;

int main() {
	long long a, b, Q;
	cin >> a >> b >> Q;
	vector<long long> s(a), t(b);
	for (int i = 0; i < a; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < b; i++) {
		cin >> t[i];
	}
	for (int q = 0; q < Q; q++) {
		long long x;
		cin >> x;
		long long s1, s2, t1, t2;
		s1 = t1 = -INF;
		s2 = t2 = INF;
		auto itr_s = lower_bound(s.begin(), s.end(), x);
		auto itr_t = lower_bound(t.begin(), t.end(), x);
		if (itr_s != s.end()) s2 = *itr_s;
		if (itr_t != t.end()) t2 = *itr_t;
		if (itr_s != s.begin()) s1 = *--itr_s;
		if (itr_t != t.begin()) t1 = *--itr_t;
		auto f = [&](long long r1, long long r2) {
			return abs(x-r1) + abs(r1-r2);
		};
		vector<long long> v1{s1, s2}, v2{t1, t2};
		long long ans = INF;
		for (long long es : v1) {
			for (long long et : v2) {
				ans = min({ans, f(es, et), f(et, es)});
			}
		}
		cout << ans << endl;
	}
	return 0;
}