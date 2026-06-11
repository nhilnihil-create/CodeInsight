#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b

signed main(){
	ll n; cin>>n;
	map<ll,ll> mp;
	rep(i,0,n){
		int a; cin>>a;
		mp[a]++;
	}
	ll m; cin>>m;
	vl t(m);
	rep(i,0,m)cin>>t[i];
	rep(i,0,m){
		if(mp[t[i]]==0){
			cout<<"NO"<<endl;
			return 0;
		}
		else mp[t[i]]--;
	}
	cout<<"YES"<<endl;
	return 0;
}