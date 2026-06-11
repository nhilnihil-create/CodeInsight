#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll n,k;
	cin>>n>>k;
	ll v[50];
	for(ll i=0;i<n;i++){
		cin>>v[i];
	}
	ll ans=0;
	for(ll i=0;i<=min(n,k);i++){
		for(ll j=0;j<=i;j++){
			vector<ll>g;
			for(ll l=0;l<j;l++){
				g.push_back(v[l]);
			}
			for(ll l=0;l<i-j;l++){
				g.push_back(v[n-1-l]);
			}
			sort(g.begin(),g.end());
			reverse(g.begin(),g.end());
			for(ll l=0;l<k-i;l++){
				if(g.size()!=0&&g[g.size()-1]<0){
					g.pop_back();
				}
			}
			ll cnt=0;
			for(auto itr=g.begin();itr!=g.end();itr++){
				cnt+=*itr;
			}
			ans=max(ans,cnt);
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}