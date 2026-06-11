#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;

	int c1 = 0, c2 = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'R') c1++;
		else c2++;
	}

	if (c1 > c2) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}