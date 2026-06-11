#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll n,x,ans=1e18;
ll a[200010],pre[200010];
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++) cin>>a[i],pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		ll c=3,sum=0;
		for(int j=n;j>=1;j-=i)
		{
			sum+=(pre[j]-pre[max(0,j-i)])*max(c,5ll),c+=2;
			if(sum>=ans) break;
		}
		ans=min(ans,sum+(i+n)*x);
	}
	cout<<ans<<endl;
	return 0;
}