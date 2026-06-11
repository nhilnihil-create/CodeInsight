#include<iostream>
#define int long long
using namespace std;
const int N=1e5+2;
const int mod=1e9+7;
int ar[N],sum[N];
int binpow(int x,int y){
	int tich=1;
	while(y){
		if(y&1){
			tich*=x;
			tich%=mod;
		}
		x*=x;
		x%=mod;
		y>>=1;
	}
	return tich;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j,k,l,ans=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>ar[i];
	}
	for(i=2;i<=n;i++){
		sum[i]=sum[i-1]+binpow(i,mod-2);
		if(sum[i]>=mod){
			sum[i]-=mod;
		}
	}
	for(i=1;i<=n;i++){
		ans+=ar[i]*(sum[i]+sum[n+1-i]+1);
		//cout<<sum[2]<<endl;
		ans%=mod;
	}
	for(i=2;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
}