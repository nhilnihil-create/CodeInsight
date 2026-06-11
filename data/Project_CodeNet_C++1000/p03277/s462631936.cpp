#include<algorithm>
#include<cstdio>
#define mxn 1000010
#define LL long long
#define mid ((l+r)>>1)
#define pii pair<int,int> 
#define fr first
#define sc second
#define mp make_pair
using namespace std;
int n,sl,fh,ans,a[mxn],tr[mxn];
pii p[mxn];
LL K;
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
void upd(int i) {for(;i<=n;i+=(i&-i)) tr[i]++;}
int qry(int i) {int res=0; for(;i;i-=(i&-i)) res+=tr[i]; return res;}
bool check(int x)
{
	int s=0;LL cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]<=x) s++;
		else s--;
		p[i]=mp(s,i);
		tr[i]=0;
		if(s>=1) cnt++;
	}
	sort(p+1,p+n+1);
	for(int l=1,i=1;i<=n;++i)
	{
		for(;l<=n&&p[l].fr<=p[i].fr-1;upd(p[l].sc),l++);
		cnt+=qry(p[i].sc);
	}
	return cnt>=K;
}
int main()
{
	n=rd();K=1ll*n*(n+1)/4+1;
	for(int i=1;i<=n;++i) a[i]=rd();
	for(int l=1,r=1e9;l<=r;)
	{
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}