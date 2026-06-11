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
	int a,b,c; cin>>a>>b>>c;
	int cnt=0;
	vi v(0);
	for(int i=1;i<=min(a,b);i++){
		if(a%i==0 && b%i==0){
			v.push_back(i);
		}
	}
	sort(all(v));
	reverse(all(v));
	cout<<v[c-1]<<endl;
	
	return 0;
}