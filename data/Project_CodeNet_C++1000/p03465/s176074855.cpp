#include <bits/stdc++.h>
using namespace std;

int n, a, J;
bitset<4000006> b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	b[0] = 1;
	for(int i = 1; i <= n; ++i) {
		cin >> a;
		b |= b << a;
		J += a;
	}
	for(int i = (J + 1) / 2; true; ++i) {
		if(b[i]) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}