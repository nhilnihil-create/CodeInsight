#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 3e5+5,mod = 998244353;

int binpow(int a,int n){
	int res = 1;
	while(n){
		if(n&1) (res*=a)%=mod,n--;
		else (a*=a)%=mod,n>>=1;
	}
	return res;
}

int inverse(int x){
	return binpow(x,mod-2);
}

vector<int> fact(N,1),inv(N,1);

void preset(){
	fact[0] = 1;
	inv[0] = 1;
	for(int i=1;i<N;i++){
		fact[i] = (fact[i-1]*i)%mod;
		inv[i] = (inv[i-1]*inverse(i))%mod;
	}
}

int nCk(int n,int k){
	if(n<k) return 0;
	return (((fact[n]*inv[k])%mod)*inv[n-k])%mod;
}

signed main(){
	int n,a,b,k,ans = 0;
	cin >> n >> a >> b >> k;
	preset();
	for(int x=0;x<=n;x++){
		if((k-x*a)%b==0){
			int y = (k-x*a)/b;
			if(y<=n && y>=0){
				ans+=nCk(n,x)*nCk(n,y)%mod;
				ans%=mod;
			}
		}
	}
	cout << ans;
}