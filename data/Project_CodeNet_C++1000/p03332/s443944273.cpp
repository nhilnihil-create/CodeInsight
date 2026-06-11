#include<bits/stdc++.h>
#pragma O3
#define int long long
using namespace std;
const int mod=998244353;
int n,a,b,k,ca,cb,ans;
int gt[3000005],rgt[3000005];
int binpow(int x,int mu){
	if(mu==1) return x%mod;
	else{
		int tmp=binpow(x,mu/2);
		if(mu%2==1) return ((tmp*tmp%mod)*x)%mod;
		else return tmp*tmp%mod;
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>a>>b>>k;
	gt[0]=1;
	for(int i=1;i<3000004;i++){
		gt[i]=(gt[i-1]%mod*(n-i+1)%mod)*(binpow(i,mod-2)%mod)%mod;
	}
	for(int ca=0;ca<=n;ca++){
		cb=(k-ca*a)/b;
		if(cb*b+ca*a!=k||cb<0) continue;
		ans=(gt[ca]*gt[cb]%mod+ans)%mod;
	}
	cout<<ans;
}