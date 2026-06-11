#include <bits/stdc++.h> // Tomasz Nowak
using namespace std;     // XIII LO Szczecin
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> w(n), s(n), f(n);
	for(int i = 0; i < n; ++i)
		cin >> w[i] >> s[i] >> f[i];

	vector<int> perm(n);
	iota(perm.begin(), perm.end(), 0);
	sort(perm.begin(), perm.end(), [&](int l, int r) {
		return s[l] + w[l] < s[r] + w[r];
	});

	int mxWeight = *max_element(s.begin(), s.end()) + *max_element(w.begin(), w.end());
	vector<long long> dp(mxWeight + 1);

	for(int i = 0; i < n; ++i) {
		int p = perm[i];
		for(int weight = s[p]; weight >= 0; --weight)
			dp[weight + w[p]] = max(dp[weight + w[p]], dp[weight] + f[p]);
	}
	cout << *max_element(dp.begin(), dp.end()) << '\n';
}
