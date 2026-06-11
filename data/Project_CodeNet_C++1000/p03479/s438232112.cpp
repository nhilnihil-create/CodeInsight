#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int64_t X, Y;
	cin >> X >> Y;

	int64_t cnt = 0;
	while (X <= Y) {
		cnt++;
		X *= 2;
	}

	cout << cnt << endl;
}