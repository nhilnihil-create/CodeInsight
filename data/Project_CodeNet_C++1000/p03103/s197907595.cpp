#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	
	ll n,m,a,b; cin >> n >> m;
	ll x=0,acum=0;
	map <ll,ll> mp; 
	
	while (n){
		n--; cin >> a >> b;
		mp[a] += b;
	}
	
	for (auto it=mp.begin() ; it!=mp.end() ; it++){
		ll p=it->first;
	
		if (acum+mp[p] >= m){
			x += (m-acum)*p; break;
		}
		else{
			x += p*mp[p];
			acum += mp[p];
		}
	}
	
	cout << x << endl;
	
	return 0;
}