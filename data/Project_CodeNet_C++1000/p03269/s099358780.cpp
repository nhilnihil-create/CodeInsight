#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF ((1ll<<60)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
int n,v[65],x[65],y[65],z[65];
int main(){
	scanf("%d",&n);
	v[19]=1;
	Rep(i,18,1) v[i]=v[i+1]*2;
	For(i,2,19){
		x[++*x]=i,y[*x]=i+1,z[*x]=0;
		x[++*x]=i,y[*x]=i+1,z[*x]=v[i];
	}
	int l=0,r=v[1]-1;
	for (;r<n;l+=v[1],r+=v[1])
		x[++*x]=1,y[*x]=2,z[*x]=l;
	For(i,2,19) if (n&v[i])
		x[++*x]=1,y[*x]=i+1,z[*x]=l,l+=v[i];
	printf("20 %d\n",*x);
	For(i,1,*x) printf("%d %d %d\n",x[i],y[i],z[i]);
}