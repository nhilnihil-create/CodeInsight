#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int n;
	cin>>n;
	long int i,a[n],s=0,d=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=n-1;i>=0;i=i-2)
	{
		s=s+a[i];
	}
	for(i=n-2;i>=0;i=i-2)
	{
		d=d+a[i];
	}
	cout<<abs(s-d)<<endl;
	
	
}