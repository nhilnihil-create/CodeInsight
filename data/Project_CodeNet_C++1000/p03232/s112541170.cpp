#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005,M=1e9+7;
int a[N],inv[N],n,ans;
int ksm(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=x*x%M)
		if (y&1)(ans*=x)%=M;
	return ans;
}
signed main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++)inv[i]=(inv[i-1]+ksm(i,M-2))%M;
	for (int i=1;i<=n;i++)(ans+=a[i]*(inv[i]+inv[n-i+1]-1))%=M;
	(ans+=M)%=M;
	for (int i=1;i<=n;i++)(ans*=i)%=M;
	printf("%lld\n",ans);
}
