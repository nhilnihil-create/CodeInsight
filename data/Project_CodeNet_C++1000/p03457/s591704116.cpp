#include<bits/stdc++.h>
using namespace std;
int dist(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}
int main () {
	long long n, T = 0, px = 0, py = 0;
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		long long t, x, y;
		cin >> t >> x >> y;
		long long dt = t - T, dx = dist(x, y, px, py);
		if ((dt >= dx && dt % 2 == dx % 2) == 0) 
		{
		    cout << "No"; 
		    return 0;
		}
		T = t;
		px = x;
		py = y;
	}
	cout << "Yes";
}