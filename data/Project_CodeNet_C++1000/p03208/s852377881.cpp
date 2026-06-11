#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int i,h[n];
	for(i=0;i<n;i++)
	{
		cin>>h[i];
	}
	sort(h,h+n);
	int s,d=h[n-1];
	for(i=0;i<=n-k;i++)
	{
		s=h[i+k-1]-h[i];
		if(s<d)
		{
			d=s;	
		}
	}
	cout<<d<<endl;
}