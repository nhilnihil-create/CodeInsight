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

const int inf = 1e9,maxn=2e5+5;
int n,a[maxn],b[maxn],c[maxn],d[maxn],dp[222];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=0;i<=28;i++){
		for(int j=1;j<=n;j++)
			c[j] = a[j]%(1<<(i+1)),
			d[j] = b[j]%(1<<(i+1));
		sort(d+1,d+n+1);
		for(int j=1;j<=n;j++){
			int x=(1<<i)-c[j], y=(1<<(i+1))-c[j];
			int t1 = lower_bound(d+1,d+n+1,x) - d;
			int t2 = lower_bound(d+1,d+n+1,y) - d;
			if(d[t2] >= y)-- t2;
			if(t2 > n)-- t2;
			if(t1<=t2 && (t2-t1+1)%2==1)dp[i]^=1;
			
			x=(1<<i)*3-c[j], y=(1<<(i+2))-c[j];
			t1 = lower_bound(d+1,d+n+1,x)-d;
			t2 = lower_bound(d+1,d+n+1,y)-d;
			if(d[t2] >= y)-- t2;
			if(t2 > n)-- t2;
			if(t1<=t2 && (t2-t1+1)%2==1)dp[i]^=1;
		}
	}
	int ans=0;
	for(int i=0;i<=28;i++)if(dp[i])ans |= (1<<i);
	printf("%d\n",ans);

	return 0;
}
