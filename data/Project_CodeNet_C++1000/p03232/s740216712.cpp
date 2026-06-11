#include<stdio.h>
typedef long long ll;
const int mod=1000000007;
int mul(int a,int b){return(ll)a*b%mod;}
int inv[100010],s[100010];
int main(){
	int n,i,x,res;
	scanf("%d",&n);
	inv[1]=1;
	for(i=2;i<=n;i++)inv[i]=-mul(mod/i,inv[mod%i]);
	for(i=1;i<=n;i++)s[i]=(s[i-1]+inv[i])%mod;
	res=0;
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		(res+=mul(x,s[i]+s[n-i+1]-1))%=mod;
	}
	for(i=1;i<=n;i++)res=mul(res,i);
	printf("%d",(res+mod)%mod);
}