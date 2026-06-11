#include<bits/stdc++.h>
#define N 100005
using namespace std;
long long i,j,k,l,s[N],S[N],n,m,ans,A[N],B[N];
struct node {
	long long x,y;
}a[N];
int main() {
	scanf("%lld%lld",&n,&m);
	for (i=1;i<=n;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
	for (i=1;i<=n;i++) s[i]=s[i-1]+a[i].y;
	for (i=n;i;i--) S[i]=S[i+1]+a[i].y;
	for (i=1;i<=n;i++) A[i]=max(A[i-1],s[i]-a[i].x);
	for (i=n;i;i--) B[i]=max(B[i+1],S[i]-(m-a[i].x));
	ans=0;
	for (i=1;i<=n;i++) ans=max(ans,s[i]-a[i].x);
	for (i=1;i<=n;i++) ans=max(ans,S[i]-(m-a[i].x));
	for (i=1;i<=n;i++) ans=max(ans,s[i]-2*a[i].x+B[i+1]);
	for (i=1;i<=n;i++) ans=max(ans,S[i]-2*(m-a[i].x)+A[i-1]);
	printf("%lld\n",ans);
}