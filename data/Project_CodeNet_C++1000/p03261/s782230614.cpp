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
	int n; cin>>n;
	set<string> s;
	char c='A';
	bool ok=true;
	rep(i,0,n){
		string t; cin>>t;
		if(s.count(t)) ok=false;
		s.insert(t);
		char d=t[0];
		if(i!=0 && c!=d) ok=false;
		c=t[t.size()-1];
	}
	if(ok)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
		
	
	return 0;
}