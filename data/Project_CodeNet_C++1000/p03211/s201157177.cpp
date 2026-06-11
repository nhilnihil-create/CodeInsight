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
	string s; cin>>s;
	int n=s.size();
	ll ans=MOD;
	rep(i,0,n-2){
		string t;
		t.push_back(s[i]);
		t.push_back(s[i+1]);
		t.push_back(s[i+2]);
		ll j=stol(t);
		ans=min(ans,abs(753-j));
	}
	cout<<ans;
	
	return 0;
}