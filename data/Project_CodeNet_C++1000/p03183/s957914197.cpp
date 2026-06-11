#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MM = 2e4 + 4;
int main() {
	int n;
	cin >> n;
	vector <int> w(n), s(n), v(n), p(n);
	for(int i = 0; i < n; i++) {
		cin >> w[i] >> s[i] >> v[i];
		p[i] = i;
	}
	sort(p.begin(), p.end(), [&](int i, int j) {
		return w[i] + s[i] < w[j] + s[j];
	});
	vector <ll> DP(MM, 0);
	for(int i : p) {
		vector <ll> ls = DP;
		for(int j = 0; j <= s[i]; j++) {
			if(j + w[i] < MM) {
				DP[j + w[i]] = max(DP[j + w[i]], ls[j] + v[i]);
			}
		}
	}
	cout << *max_element(DP.begin(), DP.end());
	return 0;
}