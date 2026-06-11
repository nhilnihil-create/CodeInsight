#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
#define inf 0x3f3f3f3f


int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		ll a,b;
		scanf("%lld%lld",&a,&b);
		if(a>b)
		swap(a,b);
		ll x=sqrt(a*b)+1;
		while(x*x>=a*b)x--;
		ll ans=2*x;
		if(x>=a)ans--;
		if(x!=0&&x==(a*b-1)/x)
		ans--;
		cout<<ans<<endl;
	}
	
	
	return 0;
}