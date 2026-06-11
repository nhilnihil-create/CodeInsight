#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define n_p(v) next_permutation(v.begin(),v.end())
#define to_ll(b) stoll(b)
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp

signed main(){
  vvi vec(3,vi(3));
  rep(i,0,3){
	int a,b,c; cin>>a>>b>>c;
    vec[i][0]=a; vec[i][1]=b; vec[i][2]=c;
  }
	bool ok=false;
	int a=vec[0][0]+vec[1][1]+vec[2][2];
    int b=vec[0][1]+vec[1][2]+vec[2][0];
    int c=vec[0][2]+vec[1][0]+vec[2][1];
  	if(a==b && b==c) ok=true;
	if(ok) cout<<"Yes";
	else cout<<"No";
	return 0;
}