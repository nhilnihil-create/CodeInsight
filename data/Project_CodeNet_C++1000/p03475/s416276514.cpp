#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> c(n - 1), s(n - 1), f(n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> c[i] >> s[i] >> f[i];
	}

	for (int i = 0; i < n - 1; i++) {
		long long ans = 0;
		for (int j = i; j < n - 1; j++) {
			if (ans <= s[j]) {
				ans = s[j] + c[j];
			} else {
				int t = ans - s[j];
				t %= f[j];
				ans += t == 0 ? 0 : f[j] - t;
				ans += c[j];
			}
		}
		cout << ans << endl;
	}
	cout << 0 << endl;

	return 0;
}