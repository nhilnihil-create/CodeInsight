#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
vector<ll> v;
ll sum;
signed main(){
	ios_base::sync_with_stdio(0);
	ll a,b;
	cin>>a>>b;
	for(ll i=1;i<=999;i++){
		sum+=i;
		v.pb(sum);
	}
	for(ll i=0;i+1<sz(v);i++){
		//cout<<v[i]<<' ';
		if(v[i]<a||v[i+1]<b) continue;
		if(v[i]-a==v[i+1]-b){
			cout<<v[i]-a;
			re 0;
		}
	}
	re 0;
}