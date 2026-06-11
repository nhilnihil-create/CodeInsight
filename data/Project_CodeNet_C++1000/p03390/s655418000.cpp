#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long a[n];
	for(int i=0;i<n;i++)
	{
		long long x,y,m;
		cin>>x>>y;
		long long t=sqrt(x*y-1);
		if(t*t>=x*y) t--;
		a[i]=t*2;
		if(t*(t+1)>=(x*y))
		a[i]--;
		if(t>=x)
		a[i]--;
		if(t>=y)
		a[i]--;
	}
	for(int i=0;i<n;i++)
	cout<<a[i]<<endl;
	return 0;
} 