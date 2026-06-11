#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	int n, m;
	n = N;
	m = 0;

	while (n) {
		m += n % 10;
		n /= 10;
	}
	//cout << m << endl;

	cout << (N % m ? "No" : "Yes") << endl;
}