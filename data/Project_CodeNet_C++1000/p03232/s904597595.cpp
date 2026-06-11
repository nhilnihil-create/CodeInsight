#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
const int mod=1e9+7;
ll n,a[N],jc1[N],jc2[N],f[N],f1[N],ans;
int main(){
    scanf("%lld",&n);jc2[n+1]=jc1[0]=1;
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<N;i++)jc1[i]=jc1[i-1]*i*1ll%mod;
    for(int i=n;i>=1;i--)jc2[i]=jc2[i+1]*i*1ll%mod;
    for(int i=1;i<n;i++)f[i+1]=jc1[i]*jc2[i+2]%mod;f[1]=jc2[2];
    for(int i=2;i<N;i++)f1[i]=(f1[i-1]+f[i])%mod;
    for(int i=0;i<n;i++)ans=(ans+(f1[i+1]+f1[n-i]+f[1])*a[i])%mod;
   	printf("%lld\n",ans);
    return 0;
}