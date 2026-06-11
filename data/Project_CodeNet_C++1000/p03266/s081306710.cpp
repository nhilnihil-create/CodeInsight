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
//priority_queue<ll, vector<ll>, greater<ll>> q;
using pl = pair<ll,ll>;
using vvb=vector<vector<bool>>;
using vb= vector<bool>;

signed main(){
	ll n; cin>>n;
	ll k; cin>>k;
	map<ll,ll> a,b;
	rep(i,1,n+1){
		ll j=-i;
		a[i%k]++;
		if(i%k==(k+(j%k))%k)b[i%k]++;
	}
	ll ans=0;
	rep(i,0,k){
		ans+=a[i]*a[i]*b[i];
	}
	cout<<ans<<endl;
	

		
	

	return 0;
}