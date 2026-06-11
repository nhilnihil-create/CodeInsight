#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
ll n;
vector<ll> a;
ll c[210000];
bool calc(ll k){
	vector<ll> pm;
	ll res = 0;
	for(int i=0;i<n;i++){
		if(a[i]<k)pm.pb(-1);
		else pm.pb(1);
	}
	for(int i=0;i<210000;i++){
		c[i]=0;
	}
	ll ze = 105000;
	ll pl = 0;
	for(int i=0;i<n;i++){
		if(pm[i] == -1){
			c[ze]++;
			ze++;
			pl -= c[ze];
			res += pl + c[ze];
		}
		else{
			c[ze]++;
			ze--;
			pl += c[ze+1];
			res += pl + c[ze];
		}
	}
	//cout<<k<<" "<<res<<endl;
	if(res >= ( n*n + n +2)/4) return true;
	else return false;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		a.pb(x);
	}
	ll lef = 1, rig = mod;
	while(rig-lef>1){
		ll mid = (lef+rig)/2;
		if( calc(mid) ){
			lef = mid;
		}
		else{
			rig = mid;
		}
	}
	cout<<lef<<endl;
	return 0;
}