#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n; cin >> n;
	int ok = 1;
	int X = 0, Y = 0, T = 0;
	for (int i = 0; i < n; ++i)
	{
		int t, x, y; cin >> t >> x >> y;
		X = abs(x - X);
		Y = abs(y - Y);
		T = t - T;
		if (X + Y > T) ok = 0;
		if ((X + Y) % 2 != T % 2) ok = 0;
	}
	cout << (ok ? "Yes" : "No") << endl;
}

