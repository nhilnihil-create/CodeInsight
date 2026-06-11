#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	int a,b,c,x,y,z;
	cin>>a>>b>>c>>x>>y;
	ll ans = 0ll;
	if(c*2<=a+b)
	{
		z = min(x,y);
		ans = ans + 2ll*z*c;
		x -= z;
		y -= z;
	}
	if(c*2<=b)
	{
		ans = ans + 2*c*y;
	}
	else		ans = ans + y*b;
	y=0;
	if(c*2<=a)
	{
		ans = ans + 2*c*x;
	}
	else		ans = ans + x*a;
	x=0;
	cout<<ans;
}