#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	if (A == B) cout << C << endl;
	else if (B == C) cout << A << endl;
	else cout << B << endl;
}
