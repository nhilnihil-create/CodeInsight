#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int mi = 1145141919, ma = 0, n;
	cin >> n;
	int a;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		mi = min(a, mi);
		ma = max(a, ma);
	}
	cout << ma - mi << endl;
	return 0;
}