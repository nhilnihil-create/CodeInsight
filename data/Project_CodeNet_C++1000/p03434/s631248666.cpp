#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	cin >> n;
	int a[n]; 
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a, a+n, greater<int>());
	int c = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i%2)
			c -= a[i];
		else 
			c += a[i];
	}
	cout << c << endl;
}

