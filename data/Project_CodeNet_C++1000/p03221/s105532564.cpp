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
using pl = pair<ll,ll>;

signed main(){
	ll n,m; cin>>n>>m;
	vvl v(n,vl(0));
	vector<pl> vp(m);
	rep(i,0,m){
		ll a,b; cin>>a>>b;
		//cout<<a<<endl;
		vp[i]=make_pair(a,b);
		--a;
		v[a].push_back(b);
	}
	rep(i,0,n)if(v[i].size()>0)sort(all(v[i]));
	rep(i,0,m){
		//cout<<'a';
		ll a,b; tie(a,b)=vp[i];
		ll j=1;
		rep(k,0,v[a-1].size()){
			//cout<<v[a-1][k];
			if(v[a-1][k]==b){
				j=k+1;
				break;
			}
		}
//		cout<<endl;
		string s=to_string(a);
		rep(i,0,6-s.size())cout<<0;
		cout<<a;
		string t=to_string(j);
		rep(i,0,6-t.size())cout<<0;
		cout<<j<<endl;
	}
		
	
	
	
	return 0;
}