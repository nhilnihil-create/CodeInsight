#include <bits/stdc++.h>
#define FI first
#define SE second
#define PB push_back
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define co(i) cout<<(i)<<endl
#define fcout cout<<fixed<<setprecision(10)
#define uni(i) i.erase(unique(i.begin(), i.end()), i.end());
#define all(i) i.begin(),i.end()
#define pint pair<int, int>
#define vint vector<int>
using namespace std;

const int INF=1e9+7;
const int MOD=1e9+7;
//const int MOD=998244353;

ll modpow(ll a,ll b,ll m){
	ll ret=1;
	while(b>0){
		if(b&1)(ret*=a)%=m;
		(a*=a)%=m;
		b>>=1;
	}
	return ret;
}

ll rev(ll a){
	return modpow(a,MOD-2,MOD);
}

int main(){
	int n; cin>>n;
	int h[100010];//h[i]=1+...+1/i
	h[1]=1;
	FOR(i,2,100001){
		h[i]=(h[i-1]+rev(i))%MOD;
	}
	ll kaijo=1;
	FOR(i,1,n+1){
		(kaijo*=i)%=MOD;
	}
	ll ans=0;
	FOR(i,0,n){
		ll a; cin>>a;
		ll b=(a*(h[i+1]+h[n-i]-1))%MOD;
		(ans+=b)%=MOD;
	}
	(ans*=kaijo)%=MOD;
	co(ans);
}
