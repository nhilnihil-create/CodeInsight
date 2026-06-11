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
//なんかむずいんだけどw
// fuck
signed main(){
	int ans=0;
	int n,a,b; cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		string s=to_string(i);
		int m=s.size();
		int c=0,d=i;
		for(int j=0;j<=m;j++){
			c+=(d%(10));
			d/=(10);
		}
		if(c>=a && c<=b)ans+=i;
	}
	cout<<ans<<endl;
		
	
	return 0;
}