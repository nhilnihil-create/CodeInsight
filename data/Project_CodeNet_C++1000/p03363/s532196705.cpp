#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<long long> A(n+1, 0);
	map<long long, long long> mp;
	mp[0]++;
	long long ans = 0, s = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		s += a;
		ans += mp[s];
		mp[s]++;
	}
	cout << ans << endl;
	return 0;
}