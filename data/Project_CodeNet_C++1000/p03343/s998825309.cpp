#include<cstdio>
#include<algorithm>
using namespace std;
#define mx 200005
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
int n,k,q,qz[mx],qp[mx],ans=2e9+5;
inline bool ck(int kl,int kr)
{
	int nl=0,nw=0,res=0;
	for(int i=1;i<=n;++i)
	{
		if(qz[i]>=kl&&qz[i]<=kr) ++nl,++nw;
		else if(qz[i]>kr) ++nl;
		else res+=max(0,min(nl-k+1,nw)),nl=nw=0;
	}
	res+=max(0,min(nl-k+1,nw)),nl=nw=0;
	return res>=q;
}
int main()
{
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",&qz[i]),qp[i]=qz[i];
	sort(qp+1,qp+n+1);
	for(int i=1;i<=n;++i)
	{
		int l=i,r=n,mid;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(ck(qp[i],qp[mid])) ans=min(ans,qp[mid]-qp[i]),r=mid-1;
			else l=mid+1;
		}
	}
	printf("%d",ans);
	return 0;
}