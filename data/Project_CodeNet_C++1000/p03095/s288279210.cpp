#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	
	int a[26] = {};
	for (int i = 0; i < n; i++) {
		a[s[i] - 'a']++;
	}
	
	const int mod = 1'000'000'007;
	long long ans = 1;
	for (int i = 0; i < 26; i++) {
		ans *= a[i] + 1;
		ans %= mod;
	}
	cout << ans - 1 << endl;

	return 0;
}