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
	ll memo1=2;
	ll memo2=1;
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	ll ans;
	rep(i,0,n-1){
		ans=memo2+memo1;
		memo1=memo2;
		memo2=ans;
	}
	cout<<ans<<endl;
	
	return 0;
}