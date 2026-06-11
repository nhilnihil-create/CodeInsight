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
	int n; cin>>n;
	vl a(n),b(n);
	rep(i,0,n)cin>>a[i];
	rep(i,0,n)cin>>b[i];
	ll k=0,l=0;
	rep(i,0,n){
		if(a[i]>b[i])k+=(a[i]-b[i]);
		else{
			ll c=b[i]-a[i];
			l+=(c+1)/2;
			if(c%2==1)k++;
		}
	}
	//cout<<k<<endl;
	//cout<<l<<endl;
	if(k<=l)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}