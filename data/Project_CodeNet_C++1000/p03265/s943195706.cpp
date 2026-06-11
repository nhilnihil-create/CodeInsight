#include <bits/stdc++.h>
using namespace std;
int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x3, y3, x4, y4;
	vector<int> xy = { x2 - x1, y2 - y1 };
	x3 = x2 - xy.at(1);
	y3 = y2 + xy.at(0);
	x4 = x3 - xy.at(0);
	y4 = y3 - xy.at(1);

	cout << x3 <<" "<< y3 << " " << x4 << " " << y4 << " " << endl;
}