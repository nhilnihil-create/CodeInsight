#include<bits/stdc++.h>
using namespace std;
int main() {
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int dx = x2 - x1, dy = y2 - y1;
	int x3, y3, x4, y4;
	swap(dx, dy); dx = -dx;
	x3 = x2 + dx, y3 = y2 + dy;
	swap(dx, dy), dx = -dx;
	x4 = x3 + dx, y4 = y3 + dy;
	cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
 	return 0;
}
