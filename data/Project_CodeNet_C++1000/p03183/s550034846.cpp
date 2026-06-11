#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	ll s,w,v;
};
node bl[1010];
ll n,f[20010],ans;
bool cmp(node a1,node b1)
{
	return a1.s+a1.w<b1.s+b1.w;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>bl[i].w>>bl[i].s>>bl[i].v;
	sort(bl+1,bl+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=20010;j>=bl[i].w;j--)
		{
			if(bl[i].s+bl[i].w>=j)
				f[j]=max(f[j],f[j-bl[i].w]+bl[i].v);
			ans=max(ans,f[j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}