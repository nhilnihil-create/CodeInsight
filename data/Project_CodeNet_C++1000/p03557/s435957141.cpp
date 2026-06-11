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
	vl a(n),b(n),c(n);
	rep(i,0,n)cin>>a[i];
	rep(i,0,n)cin>>b[i];
	rep(i,0,n)cin>>c[i];
	sort(all(a)); sort(all(b)); sort(all(c));
	ll ans=0;
	vl s(n),t(n);
	rep(i,0,n){
		ll k=b[i];
		ll p=lower_bound(all(a),k)-a.begin();
		ll q=c.end()-upper_bound(all(c),k);
		ans+=q*p;
	}
	cout<<ans<<endl;
	
	return 0;
}