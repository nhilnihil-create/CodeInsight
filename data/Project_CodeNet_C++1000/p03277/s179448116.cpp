#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define lowbit(a) a&(-a)
#define INF 0x3f3f3f3f
using namespace std;

inline int read(){
	int sum=0,f=1;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	return f*sum;
}

const int N=100001;
ll n,a[N];ll s[N];
ll c[N],tot;ll t[(N<<1)+5];

inline ll ask(int x){
	ll ret=0;
	for(int i=x;i;i-=lowbit(i)) ret+=t[i];
	return ret;
}

inline void add(int x,int k){
	for(int i=x;i<=(N<<1);i+=lowbit(i)) t[i]+=k;
}

inline bool check(int mid){
	memset(t,0,sizeof(t));s[0]=0;ll sum=0;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+(a[i]>=mid? 1:-1);
	for(int i=0;i<=n;i++){
		sum+=ask(s[i]+N);add(s[i]+N,1);
	}
	return sum>=n*(n+1)/4;
}

int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),c[i]=a[i];
	sort(c+1,c+n+1);int m=unique(c+1,c+n+1)-c-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(c+1,c+m+1,a[i])-c;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",c[r]);
	return 0;
}