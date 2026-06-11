#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
void print(ll x){
	char y=x%10+'0';
	if(x>=10)print(x/10);
	putchar(y);
}
ll n,ab=1,ans,sum,mod=1e9+7,a[100005],s[100005];
ll power(ll x,ll y){
	ll res=1;
	for(;y;x=x*x%mod,y>>=1)
		if(y&1)res=res*x%mod;
	return res;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		ab=ab*i%mod,a[i]=read();
		s[i]=(power(i,mod-2)+s[i-1])%mod;
	}
	for(int i=1;i<=n;i++)
		sum=(sum+a[i]*s[n-i+1])%mod;
	ans=ab*sum%mod;
	reverse(a+1,a+n+1);
	sum=0;
	for(int i=1;i<=n;i++)
		sum=(sum+a[i]*s[n-i+1])%mod;
	ans=(ans+ab*sum)%mod;
	for(int i=1;i<=n;i++)
		ans=(ans-a[i]*ab%mod+mod)%mod;
	print(ans);
	return 0;
}