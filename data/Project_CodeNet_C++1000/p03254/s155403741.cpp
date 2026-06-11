#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n, x; cin >> n >> x;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a+n);
	int c = 0;
	for (int i = 0; i < n; ++i)
	{
		x -= a[i];
		if (x >= 0) c++;
		else break;
	}
	if (x > 0) c--;
	cout << c << endl;
}

