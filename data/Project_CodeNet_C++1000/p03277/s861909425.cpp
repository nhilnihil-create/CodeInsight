#include<cstdio>
#include<utility>
#include<cstring>
using namespace std;
#define lowbit(i) i&(-i) 
#define ll long long
inline int read(){
	int f=1,sum=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch==EOF){return -1;}if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){sum=(sum<<1)+(sum<<3)+(ch^48);ch=getchar();}
	return sum*f;
}
int n,l,r;
ll val[200010],tree[2000010],sum[2000010];
inline int max(int i,int j){return i>j?i:j;} 
inline void updata(ll i,ll v){
    while(i<=200000){
        tree[i]+=v;
        i+=lowbit(i);
    }
    return;
}
inline ll getsum(ll i){
	ll ans=0;
	while(i>0){
		ans+=tree[i];
		i-=lowbit(i);
	}
	return ans;
}
inline bool check(int x){
	memset(tree,0,sizeof tree);
    sum[0]=0;
    for(int i=1;i<=n;i++){
    	if(val[i]>=x)sum[i]=sum[i-1]+1;
    	else sum[i]=sum[i-1]-1;
	}
    ll ans=0;
    for(int i=0;i<=n;i++){
        ans+=getsum(sum[i]+100010);
        updata(sum[i]+100010,1);
    }
    return ans<(long long)n*(n+1)/4;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)val[i]=read(),r=max(r,val[i]);
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",r);
	return 0;
}