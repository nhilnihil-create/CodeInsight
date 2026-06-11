#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define _rep(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ll long long 
#define N 1000005
typedef std::pair<int,int> pii;
int n,a[N],c[N],cpy[N],cnt,sum[N],up;
struct tree{
	void clear(){memset(c,0,sizeof(c));}
	inline void upd(int x,int v){for(;x<=up;x+=x&-x) c[x]+=v;}
	inline int qry(int x,int ret=0){for(;x;x-=x&-x) ret+=c[x]; return ret;}
} T;
/*bool check(int mid){
	T.clear();
	int ret=0; up=0;
	rep(i,1,n) sum[i]=a[i]>=mid?1:-1;
	rep(i,1,n) sum[i]+=sum[i-1],ret+=sum[i]>=0;
	rep(i,1,n) up=std::max(up,sum[i]+=n+1);
	rep(i,1,n) ret+=T.qry(sum[i]),T.upd(sum[i],1);
	return 1ll*n*(n-1)/2+n-ret<(1ll*n*(n-1)/2+n)/2+1;
}*/
inline int check(int mid) {
    memset(c,0,sizeof(c)),up=0;
    for (int i=1;i<=n;++i) {
        if (a[i]<mid) sum[i]=-1;
        else sum[i]=1;
    }
    ll res=0;
    for (int i=1;i<=n;++i) sum[i]+=sum[i-1],res+=(sum[i]>=0);
    for (int i=1;i<=n;++i) sum[i]+=n+1,up=std::max(up,sum[i]);
    for (int i=1;i<=n;++i) res+=T.qry(sum[i]),T.upd(sum[i],1);
    ll cnt=1ll*n*(n-1)/2+n;
    return cnt-res<cnt/2+1;
}
int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0),std::cout.tie(0);
	std::cin>>n;
	rep(i,1,n) std::cin>>a[i],cpy[i]=a[i];
	std::sort(cpy+1,cpy+n+1);
	cnt=std::unique(cpy+1,cpy+n+1)-cpy-1;
	rep(i,1,n) a[i]=std::lower_bound(cpy+1,cpy+cnt+1,a[i])-cpy;
	int l=1,r=cnt,ans=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
		
	}
	std::cout<<cpy[ans]<<'\n';
	return 0;
}