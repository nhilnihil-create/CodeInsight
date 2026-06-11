#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
	vector<bool> s;
	while (n) {
		s.insert(s.begin(), n % 2);
		if (n < 0)
			n = (n - 1) / -2;
		else
			n /= -2;
	}
	for (int i = 0; i < (int) s.size(); i++) {
		cout << s[i];
	}
	cout << endl;
}
