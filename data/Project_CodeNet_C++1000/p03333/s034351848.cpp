#include<bits/stdc++.h>
using namespace std;
long long n,l[111111],r[111111],ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
	}
	sort(l,l+n+1);
	reverse(l,l+n+1);
	sort(r,r+n+1);
	for(int i=0;i<n;i++)
	{
		long long c=l[i]-r[i];
		if(c<=0)
		{
			break;
		}
		ans+=2*c;
	}
	cout<<ans<<endl;
	return 0;
}