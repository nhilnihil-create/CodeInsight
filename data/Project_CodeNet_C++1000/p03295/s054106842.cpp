#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++)
	a[i]=10101010;
	for(int i=1;i<=m;i++)
	{
		int c,b;
		cin>>c>>b;
		a[c]=min(a[c],b);
	}
	int x=10101010,s=0;
	for(int i=1;i<=n;i++)
	{
		if(x==i) x=10101010,s++;
		x=min(x,a[i]);
	}
	cout<<s;
 } 