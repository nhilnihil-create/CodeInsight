#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int dx = x2 - x1, dy = y2 - y1;

	cout << x2 - dy << ' ' << y2 + dx << ' ' << x1 - dy << ' ' << y1 + dx << endl;

	return 0;
}