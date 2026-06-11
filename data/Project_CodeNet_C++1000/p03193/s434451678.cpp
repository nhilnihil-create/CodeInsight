#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1005],b[1005];
int main()
{
	int n,h,w,ans=0;
	cin>>n>>h>>w;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if(a[i]>=h&&b[i]>=w)
			ans++;
	}
	cout<<ans<<endl;
	
}