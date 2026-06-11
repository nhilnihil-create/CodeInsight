// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x, y, z, k;

	cin >> x >> y >> z >> k;

	vector<long long> a(x), b(y), c(z);

	for(int i = 0; i < x; i++) cin >> a[i];

	for(int i = 0; i < y; i++) cin >> b[i];

	for(int i = 0; i < z; i++) cin >> c[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	
	vector<long long> s;

	for(int i = 0; i < x; i++) {
		for(int j = 0; j < y; j++) {
			s.push_back(a[i] + b[j]);
		}
	}

	sort(s.begin(), s.end());

	vector<long long> s2;

	for(int i = 0; i < z; i++) {
		for(int j = (int)s.size() - 1; j >= max(0, (int)s.size() - k); j--) {
			s2.push_back(c[i] + s[j]);
		}
	}

	sort(s2.begin(), s2.end());
	
	for(int i = 0; i < k ; i++) {
		cout << s2[(int)s2.size() - i - 1] << "\n";
	}


	return 0;
}
