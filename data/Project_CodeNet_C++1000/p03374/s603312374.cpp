#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define Max int(1e5+10)
ll x[Max],v[Max],a[Max],b[Max];
int main()  
{  
    ll n,c;
    while(~scanf("%lld%lld",&n,&c))
	{
	    for(ll i=1;i<=n;i++)
	     {
	     	scanf("%lld%lld",&x[i],&v[i]);
	     	a[i]=a[i-1]-x[i]+x[i-1]+v[i];
		 }
		 x[n+1]=c;
		 for(ll i=n;i>0;i--)
	     	b[i]=b[i+1]-x[i+1]+x[i]+v[i];
	     for(ll i=2;i<=n;i++)
		     a[i]=max(a[i-1],a[i]);
		for(ll i=n-1;i>0;i--)
		     b[i]=max(b[i+1],b[i]);	 	
		ll ma=0;
		 for(ll i=1;i<=n;i++)
		 {
		 	ma=max(ma,a[i]);
		 	ma=max(ma,b[i]);
		 	ma=max(ma,a[i]-x[i]+b[i+1]);
		 	ma=max(ma,b[i]-(c-x[i])+a[i-1]);
		 }
		 printf("%lld\n",ma);
	} 
    return 0;  
      
} 