#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod ((ll)(1e9)+7)

ll pmod(ll n, ll p){
	ll m=n%mod;
	if(p==0) return 1;
	ll rtn=pmod((m*m)%mod, p/2)%mod;
	if(p%2==1) rtn=rtn*m%mod;
	return rtn;
}

int main(){
	string s;
	cin >> s;
	int n=s.length();

	vector<ll> ca(n+1, 0), cc(n+1, 0), c(n+1, 0);
	for(int i=0; i<n; i++){
		ca[i+1]=ca[i];
		cc[i+1]=cc[i];
		c[i+1]=c[i];
		if(s[i]=='A') ca[i+1]++;
		else if(s[i]=='C') cc[i+1]++;
		else if(s[i]=='?') c[i+1]++;
	}

	ll ans=0;
	for(int i=1; i<=n; i++){
		if(s[i-1]=='B' || s[i-1]=='?'){
			ll tmp1=(ca[i-1]*(cc[n]-cc[i]))%mod*(pmod(3, c[i-1]+(c[n]-c[i])))%mod;
			ll tmp2=(ca[i-1]*(c[n]-c[i])%mod)*(pmod(3, c[i-1]+(c[n]-c[i]-1)))%mod;
			ll tmp3=(c[i-1]*(cc[n]-cc[i])%mod)*(pmod(3, (c[i-1]-1)+(c[n]-c[i])))%mod;
			ll tmp4=(c[i-1]*(c[n]-c[i])%mod)*(pmod(3, (c[i-1]-1)+(c[n]-c[i]-1)))%mod;
			ans=(ans+tmp1+tmp2+tmp3+tmp4)%mod;
		}
	}
	cout << ans << endl;

	return 0;
}