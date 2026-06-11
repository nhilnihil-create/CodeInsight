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
	int x,y,n,m; cin>>n>>m>>x>>y;
	int a=x,b=y;
	int c=MOD;
	rep(i,0,n){
		int p; cin>>p;
		chmax(a,p);
	}
	rep(i,0,m){
		int p; cin>>p;
		chmax(b,p);
		chmin(c,p);
	}
	if(a>=b){
		cout<<"War"<<endl;
		return 0;
	}
	rep(i,x+1,y+1){
		if(a<i && i<=c){
			cout<<"No War"<<endl;
			//cout<<i<<endl;
			return 0;
		}
	}
	cout<<"War"<<endl;
	
	
	return 0;
}