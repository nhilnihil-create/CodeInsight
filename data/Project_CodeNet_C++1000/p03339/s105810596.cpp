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
	ll n; cin>>n;
	string s; cin>>s;
	string t=s;
	vl vec(n);
	ll cnt=0;
	rep(i,0,n){
		if(s[i]=='E')cnt++;
		vec[i]=cnt;
	}
	cnt=0;
	for(int i=n-1;i>=0;--i){
		if(s[i]=='W')cnt++;
		vec[i]+=cnt;
	}
	ll ans=MOD;
	rep(i,0,n){
		ll k=n-vec[i];
		chmin(ans,k);
	}
	cout<<ans;
	
	return 0;
}