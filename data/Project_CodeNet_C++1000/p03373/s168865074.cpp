#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	long long a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	long long ans=1000000000000000LL;
	for (long long i = 0; i <= max(x,y)*2LL; i+=2LL)
	{
		long long nans=i*c;
		nans+=max(0LL,x-i/2LL)*a;
		nans+=max(0LL,y-i/2LL)*b;
		ans=min(ans,nans);
	}
	cout<<ans<<endl;
	return 0;
}
