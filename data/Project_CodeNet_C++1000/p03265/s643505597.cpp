#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2;

	int x, y;
	x = x2 - x1;
	y = y2 - y1;

	x4 = x1 - y;
	y4 = y1 + x;
	x3 = x2 - y;
	y3 = y2 + x;

	cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << endl;
}