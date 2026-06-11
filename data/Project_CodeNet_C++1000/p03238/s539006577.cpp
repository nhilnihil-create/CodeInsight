#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
	int x;
	cin >> x;
	if (x == 1) {
		cout << "Hello World" << endl;
		return 0;
	}
	else {
		int a, b;
		cin >> a >> b;
		cout << a + b << endl;
	}

}