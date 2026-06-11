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
	int n,q; cin>>n>>q;
	string s; cin>>s;
	vi vec(n);
	int cnt=0;
	rep(i,1,n){
		if(s[i]=='C' && s[i-1]=='A') cnt++;
		vec[i]=cnt;
	}
	vi ans(n);
	rep(i,0,q){
		int l,r; cin>>l>>r;
		--l; --r;
		ans[i]=vec[r]-vec[l];
	}
	rep(i,0,q) cout<<ans[i]<<endl;
	return 0;
}