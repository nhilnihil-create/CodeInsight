#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define fo(i,j,l) for(int i=j;i<=l;++i)
#define fd(i,j,l) for(int i=j;i>=l;--i)

using namespace std;
typedef long long ll;
const ll N=5003,M=N<<1,maxn=1e18;

ll f[N];

ll qz[N][N];

int n,p[N];
ll A,B;

inline ll min(ll a,ll b)
{return a<b?a:b;}
inline ll max(ll a,ll b)
{return a>b?a:b;}

int main()
{
	scanf("%d%lld%lld",&n,&A,&B);
	fo(i,1,n)scanf("%d",&p[i]);
	++n; p[n]=n;
	fo(i,1,n){
		qz[i][i]=0;
		fd(l,i-1,1)qz[i][l]=qz[i][l+1]+(p[l]>p[i]);
	}
	p[0]=0;
	fo(i,1,n)f[i]=maxn;
	fo(i,0,n){
		int gs=0;
		fo(l,i+1,n){
			if(gs+qz[l][i+1]==l-i-1&&p[l]>p[i])
			f[l]=min(f[l],f[i]+gs*B+qz[l][i+1]*A);
			gs=gs+(p[l]<p[i]);
		}
	}
	cout<<f[n];
}