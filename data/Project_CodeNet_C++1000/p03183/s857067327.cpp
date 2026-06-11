#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int n; ll dp[1010][20010],mx[1010][20010],ans;
struct node { ll w,s,v; } d[1010];
bool cmp(node a,node b) { return a.s<b.s; }
void update(ll &x,ll y) { if (x<=y) x=y; }
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(d[i].w),read(d[i].s),d[i].s+=d[i].w,read(d[i].v);
	sort(d+1,d+n+1,cmp);
	for (int i=1;i<=n;i++) {
		for (int j=d[i].w;j<=d[i].s;j++)
			dp[i][j]=mx[i-1][j-d[i].w]+d[i].v;
		for (int j=0;j<=20000;j++) mx[i][j]=max(mx[i-1][j],dp[i][j]);
	}
	for (int j=0;j<=20000;j++) update(ans,mx[n][j]);
	printf("%lld\n",ans);
	return 0;
}