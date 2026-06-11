#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	long long ans=0,r=0,s=0;
	for(int i=0;i<n;i++)
	{
		while(r<n&& (s^a[r])==(s+a[r]))
		{
			s+=a[r];
			++r;
		}
		ans+=r-i;
		s-=a[i];
	}
	cout<<ans;
	return 0;
 } 