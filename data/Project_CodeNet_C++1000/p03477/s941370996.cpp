#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	int n, m;
	n = A + B;
	m = C + D;

	string s;
	if (n == m) {
		s = "Balanced";
	}
	else if (n > m) {
		s = "Left";
	}
	else {
		s = "Right";
	}

	cout << s << endl;
}