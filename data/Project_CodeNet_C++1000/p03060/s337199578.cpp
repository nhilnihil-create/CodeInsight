#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define fr first
#define sc second
#define pb push_back
const ll mod = 1e9+7;
const int N = 2e5+205;
void solve(){
	int n; 
	cin>>n;
	vector<ll>v; 
	for(int i=0;i<n;i++){
		ll x; 
		cin>>x; 
		v.pb(x);
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
		ll x; 
		cin>>x; 
		if(v[i]>x){
			ans+=v[i]-x;
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
