#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define re register
#define ll long long
inline int gi()
{
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
typedef pair<ll,int>pli;
typedef pair<int,int>pii;
#define mp make_pair
const int N=100010;
ll d[N];int n,siz[N];vector<pii>ans;pli p[N];
int main()
{
	n=gi();
	for(int i=1;i<=n;i++)scanf("%lld",&d[i]),p[i].first=d[i],p[i].second=i,siz[i]=1;
	sort(p+1,p+n+1);ll dis=0;
	for(int i=n;i>1;i--)
	{
		ll nd=p[i].first-n+(siz[p[i].second]<<1);
		int pos=lower_bound(p+1,p+n+1,mp(nd,0))-p;
		if(p[pos].first!=nd)return puts("-1"),0;
		int u=p[i].second,v=p[pos].second;
		ans.push_back(mp(u,v));siz[v]+=siz[u];
		dis+=siz[u];
	}
	if(dis!=p[1].first)return puts("-1"),0;
	for(pii now:ans)printf("%d %d\n",now.first,now.second);
	return 0;
}
