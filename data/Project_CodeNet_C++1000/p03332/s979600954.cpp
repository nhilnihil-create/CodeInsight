#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=300010,mod=998244353;
int ksm(int a,int b=mod-2,int c=mod){
	int ans=1;
	while(b){
		if(b&1)ans=(LL)ans*a%mod;
		b>>=1;a=(LL)a*a%mod;
	}
	return ans;
}
int n,a,b,c[N],ans;
LL k;
int main(){
	cin>>n>>a>>b>>k;
	c[0]=1;
	for(int i=1;i<=n;i++){
		c[i]=(LL)c[i-1]*(n-i+1)%mod*ksm(i)%mod;
	}
	for(int i=0;i<=n;i++){
		if((LL)a*i<=k&&(k-(LL)a*i)%b==0&&(k-(LL)a*i)/b<=n&&(k-(LL)a*i)>=0){
			int j=(k-(LL)a*i)/b;
			ans+=(LL)c[i]*c[j]%mod;
			if(ans>=mod)ans-=mod;
		}
	}
	cout<<ans<<endl;
}