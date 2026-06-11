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
/*ll gcd(ll a,ll b){
	if(a>b)swap(a,b);
	if(a==0)return b;
	return gcd(b%a,a);
}*/

signed main(){
	ll n,m; cin>>n>>m;
	string s,t; cin>>s>>t;
	ll L=n*m/gcd(n,m);
	ll a=L/n;
	ll b=L/m;
	swap(a,b);
	ll i=0,j=0;
	bool ok=true;
	while(i<n && j<m){
		if(s[i]!=t[j]){
			ok=false;
			break;
		}
		i+=a; j+=b;
	}
	cout<<(ok ? (ll)L:-1)<<endl;
	return 0;
}