#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
int a[200005],b[200005];
int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	rep(i,1,n)
	scanf("%d%d",&a[i],&b[i]);
	ll ans=0,mx=1e18,fg=0;
	rep(i,1,n)
	{
		if(a[i]<=b[i])
		{
		
		ans+=a[i];
		if(a[i]<b[i])fg=1;
	}
		else if (a[i]>b[i])
		{
			if(a[i]>b[i])fg=1;
			ans+=1ll*a[i];
			mx=min(mx,1ll*b[i]);
		}
	}
	if(fg)
	cout<<ans-mx;
	else cout<<0;
	return 0;
}