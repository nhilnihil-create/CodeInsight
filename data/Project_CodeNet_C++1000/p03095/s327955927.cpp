#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int>count(26,0);
	long long ans = 0;
	for (int i = 0; i < s.length(); i++)count.at(s.at(i) - 'a')++;
	vector<long long>a(26,0);
	a.at(0) = count.at(0);
	for (int i = 1; i < 26; i++) {
		long long res = count.at(i);
		for (int j = 0; j < i; j++)res += a.at(j)*count.at(i);
		a.at(i) = res % 1000000007;
	}
	for (int i = 0; i < 26; i++)ans += a.at(i);
	ans %= 1000000007;
	cout << ans << endl;
}