#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=(1e9)+7;
const int maxn=(1e5)+10;
int n,a[maxn];
ll iv[maxn],ans,jc=1,sum[maxn];
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	iv[0]=sum[0]=iv[1]=sum[1]=1;
	for (int i=2;i<=n;i++)
		iv[i]=mod-iv[mod%i]*(mod/i)%mod;
	for (int i=2;i<=n;i++)
		sum[i]=(sum[i-1]+iv[i])%mod;
	for (int i=1;i<=n;i++)
		ans+=a[i]*(sum[i]+sum[n-i+1]-1+mod)%mod,ans%=mod,jc=jc*i%mod;
	printf("%lld\n",ans*jc%mod);;
	return 0;
}