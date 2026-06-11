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
//(a+b-1)/b

signed main(){
/*	vvi g(3,vl(0));
	rep(i,0,n){
		int a,b; cin>>a>>b;
		-- a; -b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vi vec={0,1,2,3};
	do{
		bool ok=true;
		rep(i,0,3){
			
		}
	}while(next_permutation(all(vec)));*/
	int a=0,b=0,c=0,d=0;
	rep(i,0,6){
		int n; cin>>n;
		if(n==1)a++;
		else if(n==2)b++;
		else if(n==3)c++;
		else d++;
	}
	if(a<3 && b<3 && c<3 && d<3)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}