#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define n_p(v) next_permutation(v.begin(),v.end())
#define to_ll(b) stoll(b)
#define MOD 1000000007
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp

signed main(){
	int N; cin>>N;
	ll ans=0;
	map<ll,ll> mp;
	rep(i,0,N){
		ll a;cin>>a;
		mp[a]++;
	}
	for(auto c:mp){
		if(c.first>c.second) ans+=c.second;
		else ans+=c.second-c.first;
	}
	cout<<ans;
	
	return 0;
}