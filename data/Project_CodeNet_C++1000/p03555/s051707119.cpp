#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string a, b;
	cin >> a >> b;

	for (int i = 0; i < 3; i++) {
		if (a.at(i) != b.at(2 - i)) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}