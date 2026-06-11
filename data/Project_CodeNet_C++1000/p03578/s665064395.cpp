#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
typedef long long ll;

ll ans, mx, sum, mn = 1e8, cnt;
int main(){
	ll n;
	cin>>n;
	map <ll,ll> mp;
	for(ll i=0; i<n; i++){
		ll a;
		cin>>a;
		mp[a]++;
	}
	ll m;
	cin>>m;
	map <ll,ll> mp1;
	for(ll i=0; i<m; i++){
		ll b;
		cin>>b;
		mp1[b]++;
	}
	map<ll,ll>::iterator it;
	for(auto i : mp1){
		it=mp.find(i.first);
		if(it==mp.end()){
			cout<<"NO"<<endl;
			return 0;
		}
		else {
			if(i.second>it->second) {
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
}
