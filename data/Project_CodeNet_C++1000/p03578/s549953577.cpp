#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+6;
void solve(){
	map<ll,ll>mp;
	int n; 
	cin>>n; 
	for(int i=0;i<n;i++){
		ll x; 
		cin>>x; 
		mp[x]++;
	}
	int m; 
	cin>>m; 
	for(int i=0;i<m;i++){
		int x; 
		cin>>x; 
		mp[x]--;
		if(mp[x]<0){
			cout<<"NO"<<endl;
			return ;
		}
	}
	cout<<"YES"<<endl;
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
