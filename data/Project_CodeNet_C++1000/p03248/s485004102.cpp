// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	int n = s.length();
	s = " " + s;
	if (s[n] != '0' || s[1] != '1' || s[n - 1] != '1') {
		cout << "-1\n";
		return 0;
	}
	for (int i = 2, j = n - 2; i < j; i++, j--)
		if (s[i] != s[j]) {
			cout << "-1\n";
			return 0;
		}
	int i = 1;
	for (int j = 2; j <= n / 2; j++)
		if (s[j] == '1' || j == n / 2)
			while (i < j) {
				cout << i << ' ' << j << '\n';
				i++;
			}
	if (s[i] == '1') {
		i++;
		cout << i - 1 << ' ' << i << '\n';
	}
	for (int j = i + 1; j <= n; j++)
		cout << i << ' ' << j << '\n';
	return 0;
}
