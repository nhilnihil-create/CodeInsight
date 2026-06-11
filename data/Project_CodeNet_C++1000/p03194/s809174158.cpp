#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define RSORT(a) sort((a).rbegin(),(a).rend())
#define ll long long
#define pb(a) push_back(a)

#define PRINTV(v) {for(ll deB=0; deB<(v).size(); deB++){cout << (v)[deB] << " ";}cout << endl;}

ll pf(ll n){
	if(n==1) return 1;
	if(n%2==0) return 2;
	for(ll i=3; i*i<=n; i+=2){
		if(n%i==0) return i;
	}
	return n;
}

int main(){
	ll N,P;
	cin >> N >> P;
	
	ll ret = 1;
	
	vector<ll> v;
	
	ll t = P;
	while(t!=1){
		ll p=pf(t);
		//cout << p << endl;
		v.pb(p);
		t/=p;
	}
	
	t=1;
	ll len=0;
	REP(i,v.size()){
		if(t==v[i]) len++;
		else {t=v[i]; len=1;}
		if(len==N) {ret*=t; len=0;};
	}
	
	cout << ret << endl;

	return 0;
}