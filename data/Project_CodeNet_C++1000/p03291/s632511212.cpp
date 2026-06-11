// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int MD = 1000000007;

int main() {
	string s; cin >> s;
	int n = s.length();
	long long a = 0, b = 0, c = 0, k = 1;
	for (int i = 0; i < n; i++) {
		char x = s[i];
		if (x == 'A')
			a = (a + k) % MD;
		else if (x == 'B')
			b = (b + a) % MD;
		else if (x == 'C')
			c = (c + b) % MD;
		else {
			long long a_ = (a * 3 + k) % MD;
			long long b_ = (b * 3 + a) % MD;
			long long c_ = (c * 3 + b) % MD;
			a = a_;
			b = b_;
			c = c_;
			k = k * 3 % MD;
		}
	}
	cout << c << '\n';
	return 0;
}
