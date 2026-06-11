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
ll f(ll a,ll b){
	if(b==0)return 1;
	if(b%2==0){
		ll t=f(a,b/2);
		return t*t;
	}
	return a*f(a,b-1);
}

signed main(){
	int n; cin>>n;
	vl a(n);
	vl b(n);
	vl c(n);
	rep(i,0,n)cin>>a[i];
	rep(i,0,n){
		c[i]++;
		if(a[i]%2==1)b[i]++;
		if((a[i]-1)%2==1)b[i]++;
		c[i]++;
		if((a[i]+1)%2==1)b[i]++;
		c[i]++;
	}
	ll x=1,y=1;
	rep(i,0,n)x*=c[i],y*=b[i];
	cout<<x-y<<endl;
	//cout<<x<<" "<<y<<endl;
	return 0;
}