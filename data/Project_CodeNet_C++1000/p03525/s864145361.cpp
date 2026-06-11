#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main()
{
	int n,a[100] = {};
	cin>>n;
	for (int i = 1;i<=n;i++) cin>>a[i];
	sort(a,a+n+1);
	for (int i = 0;i<=n;i++)
	{
		if (i % 2 == 1)
		{
			if (a[i] != 0) a[i] = 24 - a[i];
		}
	}
	sort(a,a+n+1);
	int min = 24 - a[n];
	for (int i = 1;i<=n;i++)
	{
		if (min > a[i] - a[i - 1]) min = a[i] - a[i - 1];
	}
	cout<<min;
}