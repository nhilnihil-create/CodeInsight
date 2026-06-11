#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	string s = "No";

	if (abs(a - c) <= d) {
		s = "Yes";
	}
	else {
		if ((abs(a - b) <= d) && (abs(b - c) <= d)) s = "Yes";
	}

	cout << s << endl;
}