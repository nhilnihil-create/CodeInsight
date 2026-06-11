#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	ll n,m;cin>>n;
	map<ll,ll> mpa,mpb;
	rep(i,n){
		ll a;cin>>a;
		mpa[a]++;
	}
	cin>>m;
	rep(i,m){
		ll a;cin>>a;
		mpb[a]++;
	}
	for(auto i:mpb){
		if(i.second>mpa[i.first]){
			cout<<"NO"<<"\n";
			return 0;
		}
	}
	cout<<"YES"<<"\n";

}
