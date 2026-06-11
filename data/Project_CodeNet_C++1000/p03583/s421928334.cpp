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
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;

signed main(){
	ll n; cin>>n;

	rep(i,1,3600){
		rep(j,1,3600){
			double k=(4*i*j)-(j*n)-(i*n);
			if(k==0)continue;
			double l=(n*i*j)/k;
			ll a=l;
			double b=a;
			if(b==l && a>0){
				cout<<i<<" "<<j<<" "<<a<<endl;
				return 0;
			}
		}
	}



	return 0;
}