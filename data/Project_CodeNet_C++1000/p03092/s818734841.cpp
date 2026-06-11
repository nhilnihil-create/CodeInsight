#include<bits/stdc++.h>
#define to edge[i].v
#define mp make_pair
#define rint register int
#define fgx cerr<<"-------------"<<endl
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
void dbg(){cerr<<endl;}
template<typename A,typename... B>void dbg(A x,B... y){cerr<<x<<" ";dbg(y...);}
#define debug(...) cerr<<#__VA_ARGS__<<"=",dbg(__VA_ARGS__)
int pl[5050],g[5050],a[5050]; ll f[5050][5050];
inline void gao(ll &x,ll y){x=min(x,y);}
int main()
{	int tmp,n,i,j,A,B; ll ans=1e18;
	scanf("%d%d%d",&n,&A,&B);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		pl[a[i]]=i;
		for(j=i-1;j;j--)
			if(a[j]>a[i])
				g[i]++;
	}
	for(i=1;i<=n;i++)
		for(j=0;j<=n;j++)
			f[i][j]=1e18;
	f[0][0]=0; 
	for(i=0;i<n;i++)
	{
		tmp=pl[i+1];
		for(j=0;j<=n;j++)
		{
			if(j>g[tmp]) gao(f[i+1][j-1],f[i][j]+A);
			else gao(f[i+1][j],f[i][j]+B),gao(f[i+1][g[tmp]],f[i][j]);
		}
	}
	for(i=0;i<=n;i++) gao(ans,f[n][i]);
	cout<<ans;
	return 0;
}

