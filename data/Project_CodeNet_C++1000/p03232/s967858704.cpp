#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int main(){
	int i,j,n;	cin>>n;
	
	ll f[n+1],b[n+1];
	f[0]=1;
	for(i=1;i<=n;i++){
		f[i]=(i*f[i-1])%mod;
	}
	b[n]=n;
	for(i=n;i>0;i--){
		b[i-1]=((i-1)*b[i])%mod;
	}
	
	ll temp[n+1];
	temp[1]=f[n];
	for(i=2;i<=n;i++){
		temp[i]=temp[i-1];
		ll t=f[i-1];
		if(i+1<=n)	t*=b[i+1];
		t%=mod;
		temp[i]+=t;	temp[i]%=mod;
	}
	ll ans=0,sum=0;
	ll a[n+1];
	for(i=1;i<=n;i++){
		scanf("%lld",a+i);
		sum+=a[i];	sum%=mod;
		ans+=a[i]*temp[i];	ans%=mod;
		ans+=a[i]*temp[n+1-i];	ans%=mod;
	}
	ans-=sum*f[n];	ans%=mod;
	ans+=mod;	ans%=mod;
	cout<<ans<<endl;
	return 0;
}