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
	ll n; cin>>n; 
	vector<pl> v(n+1);
	vl t(n+1);
	v[0]=make_pair(0,0);
	rep(i,1,n+1){
		cin>>t[i];
		cin>>v[i].first>>v[i].second;
	}
	rep(i,1,n+1){
		ll x=abs(v[i].first-v[i-1].first);
		ll y=abs(v[i].second-v[i-1].second);
		//cout<<"x:"<<x<<" y:"<<y<<endl;
		if(t[i]-t[i-1]<x+y || (t[i]-t[i-1])%(x+y)==1){
			//cout<<i<<endl;
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	
	
	return 0;
}