#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define pb push_back
#define mk make_pair

using namespace std;
typedef long long ll;
ll mod = 998244353;
int main() {
	fastio;
	ll n;
	cin>>n;
	vector<ll> a(n,0);
	ll m = 0;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		m = max(m,a[i]);
	}
	
	ll an = 0, res = 0;
	for(ll i=0;i<n;i++){
		if(a[i]<=m/2){
			if(a[i]>an){
				an = a[i];
				res = a[i];
			}
			
		}
		else{
			if(m-a[i]>an){
				an = m-a[i];
				res = a[i];
			}
			
		}
	}
	
	cout<<m<<" "<<res<<"\n";
	
	
	
	
}




