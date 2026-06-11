#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int x[4], y[4], xh, yh;
	for (int i = 0; i < 2; ++i)
	{
		cin >> x[i] >> y[i];
	}
	xh = x[1] - x[0];
	yh = y[1] - y[0];
	y[2] = y[1] + xh;
	x[2] = x[1] - yh;
	y[3] = y[2] - yh;
	x[3] = x[2] - xh;
	cout << x[2] << " " << y[2] << " " << x[3] << " " << y[3] << endl;
	return 0;
}