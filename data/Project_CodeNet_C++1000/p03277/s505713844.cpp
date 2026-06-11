#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e5+10;
int a[N],lis[N],sum[N];
int n,m;
namespace BIT{
	const int N=::N*2;
	ll c[N];
	int mx;
	void init(int _n){mx=_n;memset(c,0,sizeof(c));}
	void insert(int x,int delta){for (;x<=mx;x+=x&-x) c[x]+=delta;}
	ll query(int x){
		ll ret=0;
		for (;x;x-=x&-x) ret+=c[x];
		return ret;
	}
}
bool check(int val){
	ll cnt=0;
	sum[0]=0;
	for (int i=1;i<=n;++i) sum[i]=sum[i-1]+(a[i]>=val?1:-1);
	BIT::init(n*2+1);
	for (int i=0;i<=n;++i){
		cnt+=BIT::query(sum[i]+n+1);
		BIT::insert(sum[i]+n+1,1);
	}
	return cnt>=1LL*n*(n+1)/4;
}
int solve(){
	int l=1,r=lis[0],mid,ret=0;
	while (l<=r){
		mid=l+r>>1;
		if (check(lis[mid])) ret=lis[mid],l=mid+1;
		else r=mid-1;
	}
	return ret;
}

int main(){
#ifndef ONLINE_JUDGE
	//freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",a+i),lis[i]=a[i];
	sort(lis+1,lis+1+n);
	lis[0]=unique(lis+1,lis+1+n)-lis-1;
	printf("%d\n",solve());
}
