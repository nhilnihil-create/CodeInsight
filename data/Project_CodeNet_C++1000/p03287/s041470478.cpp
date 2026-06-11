#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long mod(long long a, long long m) {
	a %= m;
	return a >= 0 ? a : a+m;
}

int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> s(n+1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = mod(s[i] + s[i-1], m);
	}
	map<long long, long long> mp;
	long long ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += mp[s[i]];
		mp[s[i]]++;
	}
	cout << ans << endl;
	return 0;
}