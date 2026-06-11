#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	ll n,h; cin>>n>>h;
	ll amax=0;
	vl vec(n+1);
	rep(i,0,n){
		ll a,b; cin>>a>>b;
		amax=max(amax,a);
		vec[i]=b;
	}
	sort(all(vec));
	//reverse(all(vec));
	
	ll d=0,ans=0;
	bool p=false;
	while(d<h){
		ll s=vec.size();
		ll k=vec[s-1];
		if(vec.empty() || amax>=k){
			p=true;
			break;
		}
		d+=k;
		vec.pop_back();
		++ans;
	}
	if(p){
		ll add=(h-d + amax - 1) / amax;
		ans+=add;
	}
	cout<<ans;
	return 0;
}