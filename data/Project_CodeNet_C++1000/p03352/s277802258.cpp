#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+5;
void solve(){
	int x; 
	cin>>x; 
	ll ans = 1;
	for(ll i=2;i*i<=x;i++){
		for(ll j=i*i;j<=x;j*=i){
			if(j<=x)ans = max(ans,j);
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
