//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#define ll long long
#define inf 20021225
#define bs 331
#define ull unsigned long long
using namespace std;
map<ull,int> f[20]; char ch[40]; int col[20],n; ll ans;
ull pw[20];
void calc(int fl)
{
	ull x=0,y=0;
	int p=0,q=n;
    for (int i=1;i<=n;i++)
        if(col[i]>0) x+=(ull)col[i]*pw[p],p++;
        else y+=(ull)col[i]*pw[q],q--;
	if(fl)	ans+=f[p][x+y];
	else	f[q][x+y]++;
}
void dfs1(int x)
{
	if(x>n){calc(0); return;}
	col[x]=ch[x]-'a'+1; dfs1(x+1); col[x]=-col[x]; dfs1(x+1);
}
void dfs2(int x)
{
	if(x<=n){calc(1); return;}
	col[2*n-x+1]=ch[x]-'a'+1; dfs2(x-1); col[2*n-x+1]=-col[2*n-x+1]; dfs2(x-1);
}
int main()
{
	scanf("%d",&n); scanf("%s",ch+1); pw[0]=1; for(int i=1;i<=n;i++) pw[i]=pw[i-1]*bs;
	dfs1(1); dfs2(2*n); printf("%lld\n",ans);
	return 0;
}