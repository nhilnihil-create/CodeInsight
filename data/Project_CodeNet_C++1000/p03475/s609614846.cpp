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
	vl c(n),f(n),s(n);
	//vvl s(n+1,vl(n+1));
	rep(i,0,n-1)cin>>c[i]>>s[i]>>f[i];
	rep(i,0,n){
		ll t=0;
		rep(j,i,n-1){
			if(t<s[j])t=s[j];
			else if(t%f[j]==0);
			else t+=f[j]-(t-s[j])%f[j];
			t+=c[j];
		}
		cout<<t<<endl;
			
	}
	
	return 0;
}