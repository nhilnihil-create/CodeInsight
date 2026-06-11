#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int main()
{
	int n,h,w;
	cin>>n>>h>>w;
	int a[n];
	int b[n];
	int ans=0;
	rep(i,n)
	{
		cin>>a[i];
		cin>>b[i];
		if(a[i]>=h&&b[i]>=w)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}