#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, r = 0, a = 0, b = 0, x = 0;cin >> n;
	for (int i = 0; i < n; i++) {
		string s;cin >> s;
		for (int i = 1; i < s.size(); i++)
			if (s[i - 1] == 'A'&&s[i] == 'B')r++;
		if (s[0] == 'B') b++;
		if (s.back() == 'A') a++;
		if (s[0] == 'B' && s.back() == 'A') x++;
	}
	if (a&&a == x && b == x) r--;
	cout << r + min(a, b) << endl;
}
