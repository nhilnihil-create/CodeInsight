#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int A, B;
	cin >> A >> B;

	int n, m;
	n = max(A, B);
	m = min(A, B);

	int ans = 0;
	ans += n--;
	ans += max(n, m);

	cout << ans << endl;
}