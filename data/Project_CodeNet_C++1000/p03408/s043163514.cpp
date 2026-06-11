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
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	int n;cin>>n;
	map<string,int> a;
	rep(i,0,n){
		string s; cin>>s;
		a[s]++;
	}
	int m; cin>>m;
	rep(i,0,m){
		string t; cin>>t;
		a[t]--;
	}
	int ans=-1*MOD;
	for(auto c: a){
		ans=max(ans,c.second);
	}
	ans=max(0,ans);
	cout<<ans<<endl;
	
	
	return 0;
}