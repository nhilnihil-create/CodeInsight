#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N];
int main()
{
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	int d,n;
	cin>>d>>n;
	if(n<=99)
	{
			if(d==0)cout<<n;
	if(d==1)cout<<100*n;
	if(d==2)cout<<10000*n;
	}
else
{
				if(d==0)cout<<n+1;
	if(d==1)cout<<100*(n+1);
	if(d==2)cout<<10000*(1+n);
}

	return 0;
}
