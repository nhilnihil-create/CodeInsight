#include<bits/stdc++.h>
using namespace std;
long long n,sum1,sum2,a[11000],b[11000];
int main()
{
	cin>>n;
	for(int  i=1;i<=n;i++ ) scanf("%lld",&a[i]);
	for(int  i=1;i<=n;i++ ) scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>b[i]) sum1+=a[i]-b[i];
		if(a[i]<b[i]) sum2+= (b[i]-a[i])/2;
	}
	if(sum1<=sum2) cout<<"Yes\n";
	  else cout<<"No\n";
	return 0;
 } 