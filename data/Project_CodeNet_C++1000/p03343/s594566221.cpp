#include<cstdio>
#include<cstring>
#include<algorithm>
const int N=2003,INF=0x3f3f3f3f,D=1<<11;
int n,m,q,a[N],p[N],ans=INF;
#define M (L+R>>1)
struct segment_tree{
	int mn[1<<12],mx[1<<12],s[1<<12];
	segment_tree(){memset(mn,63,sizeof mn);}
	int Min(int l,int r){
		int res=n+1;
		if(l>r)return res;
		for(l=l+D-1,r=r+D+1;l^r^1;l>>=1,r>>=1){
		  if(~l&1)res=std::min(res,mn[l^1]);
		  if( r&1)res=std::min(res,mn[r^1]);
		}return res;
	}
	int Max(int l,int r){
		int res=0;
		if(l>r)return res;
		for(l=l+D-1,r=r+D+1;l^r^1;l>>=1,r>>=1){
		  if(~l&1)res=std::max(res,mx[l^1]);
		  if( r&1)res=std::max(res,mx[r^1]);
		}return res;
	}
	int Count(int l,int r){
		int res=0;
		if(l>r)return res;
		for(l=l+D-1,r=r+D+1;l^r^1;l>>=1,r>>=1){
		  if(~l&1)res+=s[l^1];
		  if( r&1)res+=s[r^1];
		}return res;
	}
	void Update(int k,int a){
		for(k+=D,mn[k]=mx[k]=a,k>>=1;k;k>>=1)
		  mn[k]=std::min(mn[k<<1],mn[k<<1|1]),
		  mx[k]=std::max(mx[k<<1],mx[k<<1|1]);
	}
	void Erase(int k){
		for(k+=D,s[k]=1,k>>=1;k;k>>=1)
		  s[k]=s[k<<1]+s[k<<1|1];
	}
}f,g;
bool Cmp(const int&i,const int&j){return a[i]<a[j];}
int main(){
	int mn,mx,l,r;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",a+i),p[i]=i;
	std::sort(p+1,p+1+n,Cmp);
	for(int j=1,i,jj;j<=n;j++){
	  i=p[j];jj=j;
	  g=f;mx=0,mn=INF;
	  for(int k=1;k<=q;k++){
		for(;jj<=n&&(r=g.Min(p[jj]+1,n),l=g.Max(1,p[jj]-1),r-l-g.Count(l+1,r-1)<=m);jj++);
		if(jj>n)goto Brk;
		mx=std::max(mx,a[p[jj]]);
		mn=std::min(mn,a[p[jj]]);
		g.Erase(p[jj]);jj++;
	  }
	  ans=std::min(ans,mx-mn);
	  Brk:;
	  f.Update(i,i);
	}printf("%d",ans);
	return 0;
}