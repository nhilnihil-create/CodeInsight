#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b; cin >> a >> b;
	
	bool flag = false;

	for (int i = 1; i <= b; i++) {

		if (i * a == b) flag = true;

	}

	int ans = b - a;

	if (flag) ans = a + b;

	cout << ans << endl;

	return 0;
}