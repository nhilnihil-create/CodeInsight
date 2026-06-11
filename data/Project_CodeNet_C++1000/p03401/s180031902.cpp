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
	ll n; cin>>n;
	vl v(n);
	ll m=0;
	rep(i,0,n){
		cin>>v[i];
		m+=abs(v[i]-(i!=0 ? v[i-1]:0));
		if(i==n-1){
			m+=abs(v[i]);
		}
	}
	v.push_back(0);
	vl ans(0);
	rep(i,0,n){
		ll c=0;
		if(i==0){
			c-=abs(v[i]);
			c-=abs(v[i+1]-v[i]);
			c+=abs(v[i+1]);
		}
		else{
			c-=abs(v[i]-v[i-1]);
			c-=abs(v[i]-v[i+1]);
			c+=abs(v[i-1]-v[i+1]);
		}
		ans.push_back(m+c);
	}
	for(ll c:ans){
		cout<<c<<endl;
	}
			
	
	return 0;
}