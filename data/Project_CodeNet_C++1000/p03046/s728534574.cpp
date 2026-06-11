#include <bits/stdc++.h>

#define ine long long

using namespace std;

int32_t main()
{
	int n,k;
	cin >> n >> k;

	n = pow(2,n);

	if(k == 0)
	{
		for(int i=0;i<n;i++)
			cout << i << " " << i << " ";

		return 0;
	}

	if(k >= n || (n == 2 && k == 1))
	{
		cout << -1 << endl;
		return 0;
	}

	cout << k << " ";

	for(int i=0;i<n;i++)
	{
		if(i != k)
			cout << i << " ";
	}

	cout << k << " ";

	for(int i=n-1;i>=0;i--)
	{
		if(i != k)
			cout << i << " ";
	}
}
