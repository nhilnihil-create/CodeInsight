#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,d;
	int c = 1000000;
	int b = 0;
	cin >> n;
	for (int i=0; i<n ; i++)
	{
		cin >> a;
		while (a == (a/2)*2 )
		{
			b += 1;
			a /= 2;
		}
		if (b < c)
		{
			c = b;
			b= 0;
		}
		else
		{
			b = 0;
		}
		
	}
	cout << c << endl;
	
}