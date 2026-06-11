#include<bits/stdc++.h>
using namespace std;

int main() {
	int a[3], b[3];
	for (int i = 0; i < 3; ++i) cin >> a[i] >> b[i];

	int cnt[5] = {};
	for (int i = 0; i < 3; i++) {
		cnt[a[i]]++;
		cnt[b[i]]++;
	}

	int c1 = 0, c2 = 0;
	for (int i = 1; i <= 4; i++) {
		if (cnt[i] == 1) c1++;
		else if (cnt[i] == 2) c2++;
	}

	cout << (c1 == 2 && c2 == 2 ? "YES" : "NO") << endl;
	return 0;
}