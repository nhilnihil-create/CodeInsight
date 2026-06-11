// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9,maxn=2e5+5;

int n,a[maxn],sum[maxn];

void solve(int l,int r,int &a1,int &a2){
	int le = l, ri = r-1, res=inf;
	while(le <= ri){
		int mid=le+ri>>1;
		int x = sum[mid]-sum[l-1];
		int y = sum[r]-sum[mid];
		if(abs(x-y) < res){
			res = abs(x-y);
			a1 = x;a2 = y;
		}
		if(x<=y)le=mid+1;
		else ri=mid-1; 
	}
}

signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]), sum[i]=sum[i-1]+a[i];
	
	int res=inf;
	for(int i=2;i<=n-2;i++){
		int p,q,r,s;
		solve(1,i,p,q);
		solve(i+1,n,r,s);
		res = min(res, max(max(p,q),max(r,s)) - min(min(p,q),min(r,s)));
	}
	printf("%lld\n",res);

	return 0;
}
