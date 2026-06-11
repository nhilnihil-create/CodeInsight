
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll Q,a,b;
bool check(ll c)
{
	//f[x]=-x^2+(a+c+1)*x 
	ll A=-1,B=(a+c+1);
	ll po=-B/(2ll*A);
	//cout<<po<<'\n';
	for(ll i=max(1ll,po-500);i<=min(c,po+500);i++)
	{
		if(i*(a+c-i+1)>=a*b)
			return false;
	}
	return true;
}
 
int main()
{	
	cin>>Q;
	while(Q--)
	{
		cin>>a>>b;
		if(a>b)
			swap(a,b);
		ll l=1,r=b,p;
		while(l<=r)
		{
			ll mid=l+r>>1;
			if(check(mid))
				l=mid+1,p=mid;
			else
				r=mid-1;
		}
		ll res=a-1+p;	
		cout<<res<<'\n';
	}	
	return 0;
}