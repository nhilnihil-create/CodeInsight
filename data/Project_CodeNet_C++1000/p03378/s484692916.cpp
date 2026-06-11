#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n, m, x;
	cin >> n >> m >> x;
	int l = 0, r = 0, in;
	for (int i = 0; i < m; ++i)
	{
		cin >> in;
		l += (in < x);
		r += (in > x);
	}
	cout << min(l, r) << endl;
	return 0;
}