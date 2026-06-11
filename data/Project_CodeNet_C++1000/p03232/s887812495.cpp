#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=1e5;
ll A[MAX_N];
int N;
const ll MOD=1e9+7;
ll mpw(ll n,ll m){
	ll ret=1;
	while(m){
		if (m&1){
			ret*=n;
			ret%=MOD;
		}
		n*=n;
		n%=MOD;
		m>>=1;
	}
	return ret;
}
ll minv(ll n){
	return mpw(n,MOD-2);
}
ll psm[MAX_N];
int main(){
	cin>>N;
	REP(i,N)cin>>A[i];
	psm[0]=1;
	REP(i,N-1){
		psm[i+1]=psm[i]+minv(i+2);
	}
	ll ans=0;
	REP(i,N){
		ans+=A[i]*((psm[i]-psm[0]+psm[N-1-i]+2*MOD)%MOD)%MOD;
		ans%=MOD;
	}
	REP(i,N){
		ans*=(i+1);
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}