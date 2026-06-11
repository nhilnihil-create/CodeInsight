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
	ll a,b,c; cin>>a>>b>>c;
	ll n; cin>>n;
	ll ans=0;
	rep(i,0,n+1){
		rep(j,0,n+1){
			ll k=a*i+b*j;
			if(n-k==0){
				ans++;
				//cout<<i<<" "<<j<<" "<<endl;
			}
			else if(n-k>=0 && (n-k)%c==0){
				ans++;
				//cout<<i<<" "<<j<<" "<<endl;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
	ll cnt=0;
	rep(i,0,n+1){
		rep(j,0,n+1){
			rep(k,0,n+1){
				if(a*i+b*j+c*k==n)cnt++;
			}
		}
	}
	//cout<<cnt<<endl;
	return 0;
}