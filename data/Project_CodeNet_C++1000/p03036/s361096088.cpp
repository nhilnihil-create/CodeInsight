// abc127_b.cc
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long r, d, x;
	cin >> r >> d >> x;

	for (int i = 0; i < 10; i++) {
		long long t = r * x - d;
		cout << t << "\n";
		x = t;
	}
}