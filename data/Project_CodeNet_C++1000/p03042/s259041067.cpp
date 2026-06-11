#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int GCD(int a, int b) {
	if (!b) return a;
	else {
		return GCD(b, a % b);
	}
}

int main() {
	int S;
	cin >> S;

	int n, m;
	n = S / 100;
	m = S % 100;

	bool a, b;
	a = b = 1;

	if ((m < 1) || (m > 12)) a = false;
	if ((n < 1) || (n > 12)) b = false;

	if (a & b) cout << "AMBIGUOUS" << endl;
	else if (a) cout << "YYMM" << endl;
	else if (b) cout << "MMYY" << endl;
	else cout << "NA" << endl;
}