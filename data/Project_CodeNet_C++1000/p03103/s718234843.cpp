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
using pl = pair<long long,long long>;

signed main(){
	ll n,k; cin>>n>>k;
	vector<pl> v(n);
	rep(i,0,n)cin>>v[i].first>>v[i].second;
	ll ans=0;
	sort(all(v));
	rep(i,0,n){
		if(k<=v[i].second){
			ans+=v[i].first*k;
			break;
		}
		else{
			ans+=(v[i].first)*(v[i].second);
			k-=v[i].second;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}