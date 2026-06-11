#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,d,m;
	bool f=true;
	map<ll,ll>mp;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>d;
		mp[d]++;
	}
	cin>>m;
	for(ll i=0;i<m;i++){
		cin>>d;
		mp[d]--;
		if(mp[d]<0){
			f=false;
		}
	}
	if(f){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}

