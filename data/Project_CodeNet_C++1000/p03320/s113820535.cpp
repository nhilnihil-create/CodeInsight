#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
typedef long long ll;

typedef pair<double,ll> P;

int digit(ll n){
	int ret=0;
	while(n>0){
		n/=10;
		ret++;
	}
	return ret;
}

int ds(ll n){
	int ret=0;
	while(n>0){
		ret+=n%10;
		n/=10;
	}
	return ret;
}

int main(){
	ll K;
	cin>>K;
	ll N=1;
	REP(i,K){
		set<P> s;
		int d=digit(N);
		ll p=1;
		REP(j,d){
			p*=10;
			REP(k,10){
				ll x=N/p*p+k*p/10+p/10-1;
				if (x>=N){
					s.insert(P((double)x/ds(x),x));
				}
			}
		}
		auto ite=s.begin();
		cout<<ite->second<<endl;
		N=ite->second+1;
	}
	return 0;
}