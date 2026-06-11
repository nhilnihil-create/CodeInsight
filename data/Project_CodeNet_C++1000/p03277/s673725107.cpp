#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
int n,a[N],Ha[N],hs,k,f[N];
struct BIT{
	int n,c[N];
	void set(LL _n){
		n=_n;
		memset(c,0,sizeof c);
	}
	void add(int x,int d){
		for (;x<=n;x+=x&-x)
			c[x]+=d;
	}
	int ask(int x){
		int ans=0;
		for (;x;x-=x&-x)
			ans+=c[x];
		return ans;
	}
}T;
bool check(int k){
	for (int i=1;i<=n;i++)
		f[i]=f[i-1]+(a[i]>=k?1:-1);
	T.set(n*2+1);
	LL ans=0;
	for (int i=0;i<=n;i++){
		ans+=T.ask(f[i]+n+1);
		T.add(f[i]+n+1,1);
	}
	return ans>=1LL*n*(n+1)/4;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),Ha[i]=a[i];
	sort(Ha+1,Ha+n+1);
	hs=unique(Ha+1,Ha+n+1)-Ha-1;
	for (int i=1;i<=n;i++)
		a[i]=lower_bound(Ha+1,Ha+hs+1,a[i])-Ha;
	int L=1,R=hs,mid,ans=L;
	while (L<=R){
		mid=(L+R)>>1;
		if (check(mid))
			L=mid+1,ans=mid;
		else
			R=mid-1;
	}
	printf("%d",Ha[ans]);
	return 0;
}