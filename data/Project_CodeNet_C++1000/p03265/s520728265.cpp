#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int x = x2 - x1, y = y2 - y1;
	swap(x, y), x *= -1;
	x2 += x, y2 += y; cout << x2 << " " << y2 << " ";
	swap(x, y), x *= -1;
	x2 += x, y2 += y; cout << x2 << " " << y2 << "\n";
	
	return 0;
}
