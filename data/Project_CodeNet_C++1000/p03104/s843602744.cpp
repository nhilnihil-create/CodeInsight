#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+5;
ll f(ll x){
	if(x%4==0)return x;
	if(x%4==1)return 1ll;
	if(x%4==2)return x+1ll;
	return 0;
}
void solve(){
	ll a,b; 
	cin>>a>>b;
	ll ans = f(a-1);
	ans^=f(b);
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
