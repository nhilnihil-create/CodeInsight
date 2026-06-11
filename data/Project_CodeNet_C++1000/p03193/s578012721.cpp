#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	ll n,h,w,ans=0;
	cin>>n>>h>>w;
	for(int i=1;i<=n;i++) 
	{
		ll a,b;
		cin>>a>>b;
		if(a>=h&&b>=w) ans++;
	}
	cout<<ans<<endl;
}