#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n, T;
	cin >> n >> T;
	int k = 1000000;
	for (int i = 0; i < n; ++i)
	{
		int c, t;
		cin >> c >> t;
		if (t <= T)
			k = min(k, c);
	}
	if (k == 1000000)
		cout << "TLE";
	else
		cout << k;
}