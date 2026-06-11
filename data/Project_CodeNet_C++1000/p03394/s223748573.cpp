#include<bits/stdc++.h>

using namespace std;

int a[] = {6 , 2 , 10 , 3 , 9 , 4 , 8 , 12};
int b[] = {2 , 10 , 3 , 9 , 4 , 8 , 6 , 12};
int n;

int main()
{
	cin >> n;
	if(n == 3)
	{
		cout << 2 << " " << 5 << " " << 63;
		return 0;
	}
	if(n % 2 == 1)
	{
		for(int i = 0 ; i < min(n , 8) ; i++)
			cout << a[i] << " ";
		for(int i = 8 ; i < n ; i++)
		{
			a[i % 8] += 12;
			cout << a[i % 8] << " ";
		}
	}
	else
	{
		for(int i = 0 ; i < min(n , 8) ; i++)
			cout << b[i] << " ";
		for(int i = 8 ; i < n ; i++)
		{
			b[i % 8] += 12;
			cout << b[i % 8] << " ";
		}
		/*
		for(int i = 0 ; i < 8 ; i++)
			cout << b[i] << " ";
		*/
	}
}
