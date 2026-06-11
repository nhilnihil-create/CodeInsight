#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll ppow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=(res*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return res;
}
ll sum[200000];
int a[200000];
signed main(){
	sum[1]=1;
	for(int i=2;i<200000;i++){
		sum[i]=(sum[i-1]+ppow(i,MOD-2))%MOD;
	}
	int n;scanf("%d",&n);
	ll ans=0;
	rep(i,n){
		scanf("%d",&a[i]);
		(ans+=a[i]*sum[i+1]%MOD+a[i]*sum[n-i]%MOD+MOD-a[i])%=MOD;
	}
	for(int i=1;i<=n;i++)(ans*=i)%=MOD;
	cout<<ans<<endl;
}