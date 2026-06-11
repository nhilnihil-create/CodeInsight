#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

int l,r,ans=0,pos=1;

signed main()
{
	cin>>l>>r;
	pos=l;
	
	while (pos<=r)
	{
		pos*=2ll;
		ans++;
	}
	cout<<ans<<endl;
		
	return 0;
}