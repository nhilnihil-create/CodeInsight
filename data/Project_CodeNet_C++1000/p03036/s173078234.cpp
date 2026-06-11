#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int64_t r, D, x;
	cin >> r >> D >> x;

	for (int i = 0; i < 10; i++) {
		x = x * r - D;
		cout << x << endl;
	}
}