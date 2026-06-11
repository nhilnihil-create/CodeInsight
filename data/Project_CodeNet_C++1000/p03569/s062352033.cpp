#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int N = s.length();
	int i = 0, j = N - 1, ans = 0;
	while (i < j) {
		while (s[i] == 'x' && s[j] == 'x') {
			if (i < N - 1) i++;
			if (j > 0) j--;
			if (i >= j) break;
		}
		while (s[i] == 'x' && s[j] != 'x') {
			ans++;
			if (i < N - 1) i++;
			if (i >= j) break;
		}
		while (s[i] != 'x' && s[j] == 'x') {
			ans++;
			if (j > 0) j--;
			if (i >= j) break;
		}

		if (s[i] != s[j]) {
			cout << -1 << endl;
			return 0;
		}
		i++;
		j--;
	}
	cout << ans << endl;
}