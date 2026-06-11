#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int ans = 10000000;
	for (int a = 1; a < n; a++) {
		int b = n - a;

		string sa = to_string(a);
		string sb = to_string(b);

		int va = 0, vb = 0;
		for (int i = 0; i < sa.size(); i++) {
			va += (sa[i] - '0');
		}
		for (int i = 0; i < sb.size(); i++) {
			vb += (sb[i] - '0');
		}
		if (ans > va + vb) {
			ans = va + vb;
		}

	}
	cout << ans << endl;
	return 0;
}