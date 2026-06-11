#include<bits/stdc++.h>
using namespace std;
#define go(i,a,b) for(int i=(a);i<=(b);++(i))
#define com(i,a,b) for(int i=(a);i>=(b);--(i))
#define mem(a,b) memset((a),(b),sizeof(a))
#define inf 0x3f3f3f3f
#define fin freopen("input.txt","r",stdin)
#define fout freopen("output.txt","w",stdout)
typedef long long ll;
int n,A,B,x,p[5005];
ll f[5005][5005],pre[5005][5005];

void gmin(ll &a,ll b){if(a>b) a=b;}

int main()
{
	//fin;
	scanf("%d%d%d",&n,&A,&B);
	go(i,1,n) scanf("%d",&x),p[x]=i;
	mem(f,0x3f),mem(pre,0x3f);
	go(i,1,n) pre[0][i]=0;
	go(i,1,n)
	go(j,1,n){
		if(p[i]>j) gmin(f[i][j],pre[i-1][j]+B);
		else if(p[i]==j) gmin(f[i][j],pre[i-1][j]);//允许i-1在自己左边的空格或者和自己一个空格
		//保证了对于任意数比它小一的的数都在它左边，即升序排列 
		else gmin(f[i][j],pre[i-1][j]+A);
		pre[i][j]=pre[i][j-1];
		gmin(pre[i][j],f[i][j]); 
	}
	ll ans=1e18;
	go(i,1,n) ans=min(ans,f[n][i]);
	printf("%lld",ans);
	return 0;
}