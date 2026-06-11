#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> s(n);
	int ans = 0, a = 0, b = 0;
	bool f = true;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].length() - 1; j++) {
			if (s[i][j] == 'A' && s[i][j + 1] == 'B') {
				j++;
				ans++;
			}
		}

		if (s[i][s[i].length() - 1] != 'A' && s[i][0] == 'B') {
			f = false;
		} else if (s[i][s[i].length() - 1] == 'A' && s[i][0] != 'B') {
			f = false;
		}
		if (s[i][s[i].length() - 1] == 'A') {
			a++;
		}
		if (s[i][0] == 'B') {
			b++;
		}
	}

	if (min(a, b) != 0) {
		ans += min(a, b) - (f ? 1 : 0);
	}
	cout << ans << endl;

	return 0;
}