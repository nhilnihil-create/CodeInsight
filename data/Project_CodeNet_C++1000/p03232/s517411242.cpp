#include <bits/stdc++.h>
#define int long long
#define P pair<int,int>
#define inf (int)(3e18)
#define mod (int)(1e9+7)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int n,sum[114514];
int a[114514];
int mod_pow(int x,int y,int z){
	int res=1;
	while(y>0){
		if(y&1)res*=x;
		res%=z;
		x*=x;x%=z;
		y>>=1;
	}
	return res;
}
void init(){
	int now=1;
	for(int i=1;i<=n;i++){
		now*=i;now%=mod;
	}
	for(int i=1;i<=n;i++){
		sum[i]=now*mod_pow(i,mod-2,mod)%mod;
		sum[i]+=sum[i-1];sum[i]%=mod;
	}
}
signed main(){
	cin>>n;
	init();
	rep(i,n)cin>>a[i];
	int ans=0;
	rep(i,n){
		int memo=sum[i+1];
		memo+=sum[n-i]-sum[1];
		ans+=a[i]*memo;ans%=mod;
	}
	cout<<ans<<endl;
}
