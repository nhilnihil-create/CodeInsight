#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<pair<int,int>> dt(n);
	for (int i = 0; i < n; i++) {
		int t, d; cin >> t >> d;
		dt.at(i) = make_pair(d, t);
	}
	sort(dt.rbegin(), dt.rend());
	vector<int> v1, v2;
	set<int> s;
	vector<long long> f(n + 1, 0);
	long long sum = 0;
	int cur;
	for (int i = 0; i < n; i++) {
		if (i < k) sum += dt.at(i).first;
		if (s.count(dt.at(i).second)) {
			if (i < k) v1.push_back(dt.at(i).first);
		} else {
			s.insert(dt.at(i).second);
			if (i >= k) v2.push_back(dt.at(i).first);
		}
		if (i == k - 1) {
			f.at(s.size()) = sum;
			cur = s.size();
		}
	}
	reverse(v1.begin(), v1.end());
	int cur1 = 0, cur2 = 0;
	while (cur1 < v1.size() && cur2 < v2.size()) {
		f.at(cur + 1) = f.at(cur) - v1.at(cur1) + v2.at(cur2);
		cur++; cur1++; cur2++;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (f.at(i) > 0) ans = max(ans, f.at(i) + (long long)i * i);
	}
	cout << ans << endl;
}