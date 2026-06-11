#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
int main()
{
	cin>>n;
	for(long long l=1,r;l<=n;l=r+1)
	{
		r=(n/l)?(n/(n/l)):n;
		if(n/l==0) continue;
		long long tval=n/(n/l)-1;
		if(tval&&n/tval==n%tval) ans+=tval;
	}
	cout<<ans<<endl;
}