#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010;
ll f[N][N<<1];
int n,a[N],x;
ll A,B;
ll pan(int x,int y)
{
	if (x<y) return B;
	else if (x>y) return A;
	else return 0;
}
ll pan1(int x,int y)
{
	if (x-1>=y) return A;
	else return B;
}
int main() {
	scanf("%d",&n);
	scanf("%lld%lld",&A,&B);
	for (int i=1;i<=n;i++) scanf("%d",&x),a[x]=i;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n*2+1;j++) 
		 if (j%2==0) f[i][j]=f[i-1][j-1]+pan(j/2,a[i]);
		 else f[i][j]=f[i-1][j]+pan1(j/2+1,a[i]);
		for (int j=2;j<=n*2+1;j++) f[i][j]=min(f[i][j],f[i][j-1]); 
	}
	ll ans=10000000000000000;
	for (int i=1;i<=n*2+1;i++) ans=min(ans,f[n][i]);
	cout << ans << endl;
} 