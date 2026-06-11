#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;

#define fr first
#define sc second

ll S(ll n){
	ll ret=0;
	while(n>0){
		ret+=n%10;
		n/=10;
	}
	return ret;
}

int main(){
	ll k;
	cin>>k;
	
	ll POW[16];
	POW[0]=1;
	for(int i=1;i<16;i++){
		POW[i]=POW[i-1]*10;
	}
	
	vector<ll> ret;
	for(int d=0;d<=15;d++){
		ll B=9*d-1;
		if(d==0)B=0;
		for(int a=0;a<=min(9*(ll)d+200,POW[15-d]);a++){
			if(a%10==9)continue;
			if(a-S(a)<=B)ret.push_back(a*POW[d]+POW[d]-1);
		}
	}
	//cout<<ret.size()<<endl;
	sort(ret.begin(),ret.end());
	for(int i=1;i<=k;i++){
		printf("%lld\n",ret[i]);
		//cout<<ret[i]<<" "<<S(ret[i])/(ld)(ret[i])<<endl;
	}
}

