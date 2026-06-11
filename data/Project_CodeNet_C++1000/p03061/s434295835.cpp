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
	ll n; cin>>n;
	vl a(n);
	rep(i,0,n)cin>>a[i];
	vl r(n+10),l(n+10);
	r[n+1]=0; l[0]=0;
	rep(i,1,n+1){
		l[i]=gcd(l[i-1],a[i-1]);
		r[n+1-i]=gcd(r[n+2-i],a[n-i]);
	}
		
	ll ans=1;
	rep(i,1,n+1){
		ll g=gcd(l[i-1],r[i+1]);
		ans=max(ans,g);
	}
	cout<<ans<<endl;
	
	return 0;
}
