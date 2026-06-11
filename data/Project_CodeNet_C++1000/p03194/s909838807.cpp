#include<iostream>
#include<map>
using namespace std;
typedef long long ll;

int main(){
	ll n,p;
	map<ll,ll> yakusuu;
	cin >> n >> p;
	while(p%2==0){
		yakusuu[2]++;
		p/=2;
	}
	for(ll i=3;i*i<=p;i+=2){
		while(p%i==0){
			yakusuu[i]++;
			p/=i;
		}
	}
	yakusuu[p]++;
	ll ans=1;
	for(auto itr=yakusuu.begin();itr!=yakusuu.end();itr++){
		ll x=itr->second/n;
		while(x--) ans*=itr->first;
	}
	cout << ans << endl;
	return 0;
}
