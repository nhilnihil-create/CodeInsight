#include <bits/stdc++.h>

using namespace std;

int main() {
	int k;
	cin >> k;
	int cnt = 0;
	for (int i = 1; i <= k; ++i) if (i % 2 == 0)
		for (int j = 1; j <= k; ++j) if (j % 2)
			cnt++;
	cout << cnt << endl;
	return 0;
}