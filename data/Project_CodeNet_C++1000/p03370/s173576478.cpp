#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n, x; cin >> n >> x;
	int minval = 1e9;
	for (int i = 0; i < n; ++i)
	{
		int m; cin >> m;
		x -= m; 
		minval = min(minval, m);
	}
	cout << n + x / minval << endl;
}
