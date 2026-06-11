#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int n, m;
	n = min(A, B);
	m = max(A, B);

	if ((n <= C) && (m >= C)) cout << "Yes" << endl;
	else cout << "No" << endl;
}