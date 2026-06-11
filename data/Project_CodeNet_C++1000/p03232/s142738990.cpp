#include<iostream>
using namespace std;
const int N=1e6+10,mod=1e9+7;
int n,a[N],f[N],g[N],E[N],inv[N],Ans;
int main()
{
	cin>>n;inv[1]=1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=2;i<=n;i++) inv[i]=mod-1ll*mod/i*inv[mod%i]%mod;
	for(int i=1;i<=n;i++) f[i]=1ll*g[i-1]*inv[i]%mod+1,g[i]=(g[i-1]+f[i])%mod;
	for(int i=1;i<=n;i++) E[i]=(f[i]+f[n-i+1]-1)%mod;
	for(int i=1;i<=n;i++) (Ans+=1ll*E[i]*a[i]%mod)%=mod;
	for(int i=1;i<=n;i++) Ans=1ll*Ans*i%mod;
	cout<<(Ans+mod)%mod<<endl;
}
