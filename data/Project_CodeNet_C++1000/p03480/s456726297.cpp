// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	int n = s.length();
	int k = n;
	for (int i = 1; i < n; i++)
		if (s[i - 1] != s[i])
			k = min(k, max(i, n - i));
	cout << k << '\n';
	return 0;
}
