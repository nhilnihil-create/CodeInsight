#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int ax, ay, bx, by;
	ax= x2 - x1;
	ay= y2 - y1;
	bx = -ay;
	by = ax;
	int x3, y3, x4, y4;
	x3 = x2 + bx;
	y3 = y2 + by;
	x4 = x1 + bx;
	y4 = y1 + by;
	cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
	return 0;
}