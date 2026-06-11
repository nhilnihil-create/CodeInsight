#include<iostream>
#include<cstdio>
#include<cstring>
#define ull unsigned long long
using namespace std;
const int N=2*(1e5)+10;
const ull inf=1ULL<<63;
ull a[N],mn[N],val[N],sum[N];
int n;
ull ans,cost;
ull Sum(int l,int r){return sum[r]-sum[max(l-1,0)];}

int main(){
#ifndef ONLINE_JUDGE
	//freopen("a.in","r",stdin);
#endif
	ull tmp;
	scanf("%d",&n); cin>>cost;
	sum[0]=0;
	for (int i=1;i<=n;++i) cin>>a[i],sum[i]=sum[i-1]+a[i];
	for (int i=2;i<=n;++i) val[i]=2LL*i+1;
	val[1]=5;
	ans=inf;
	for (int k=1;k<=n;++k){
		tmp=0;
		for (int loc=n,i=1;loc>=1;loc-=k,++i)
			tmp+=val[i]*Sum(loc-k+1,loc);	
		ans=min(ans,tmp+cost*k);
	}
	cout<<ans+cost*n<<endl;
}
