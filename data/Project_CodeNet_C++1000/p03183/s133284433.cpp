#include <bits/stdc++.h>
#define re register
#define LL long long
#define SIZE 1005
using namespace std;
int n;
struct Node
{
	LL w,s,v;
}bl[SIZE];
LL dp[20005],ans=0;
inline bool cmp(Node x,Node y)
{
	return x.w+x.s<y.w+y.s;
}
int main()
{
	cin>>n;
	for(re int i=1;i<=n;++i)
		cin>>bl[i].w>>bl[i].s>>bl[i].v;
	sort(bl+1,bl+n+1,cmp);
	for(re int i=1;i<=n;++i)
		for(re int j=20001;j>=bl[i].w;--j)
			if(bl[i].s+bl[i].w>=j)
				dp[j]=max(dp[j],dp[j-bl[i].w]+bl[i].v),ans=max(ans,dp[j]);	
	cout<<ans<<endl;
	return 0;
} 