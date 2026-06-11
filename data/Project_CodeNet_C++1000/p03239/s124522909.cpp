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
using pl = pair<ll,ll>;
signed main(){
	ll n,t; cin>>n>>t;
	vector<pl> vec(n);
	ll ans=MOD;
	rep(i,0,n)cin>>vec[i].second>>vec[i].first;
	sort(all(vec));
	rep(i,0,n){
		if(vec[i].first>t)break;
		chmin(ans,vec[i].second);
	}
	if(ans==MOD)cout <<  "TLE" << endl;
	else cout << ans << endl;
	return 0;
}