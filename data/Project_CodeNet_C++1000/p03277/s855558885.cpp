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
#define ll long long
#define REP(a,b,c) for(int a=b;a<=c;a++)
#define re register
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
typedef pair<int,int> pii;
#define mp make_pair
inline int gi()
{
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
const int N=100010;
int n,a[N],o[N],v[N],c[N<<1],s[N];
ll all;
int lowbit(int x){return x&(-x);}
void Add(int x,int d){while(x<=(n<<1)){c[x]+=d;x+=lowbit(x);}}
int query(int x){int ret=0;while(x){ret+=c[x];x-=lowbit(x);}return ret;}
bool check(int mid)
{
	for(int i=1;i<=n;i++)v[i]=(a[i]>=o[mid])?1:-1;
	ll ret=0;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+v[i],ret+=(s[i]<0);
	memset(c,0,sizeof(c));
	for(int i=n;i;i--)
	{
		ret+=query(s[i]+n-1);
		Add(s[i]+n,1);
	}
	return ret*2<=all;
}
int main()
{
	n=gi();all=1ll*n*(n+1)/2;
	for(int i=1;i<=n;i++)a[i]=o[i]=gi();sort(o+1,o+n+1);int tot=unique(o+1,o+n+1)-o-1;
	int l=1,r=tot,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)){ans=mid;l=mid+1;}
		else r=mid-1;
	}
	printf("%d\n",o[ans]);
	return 0;
}
