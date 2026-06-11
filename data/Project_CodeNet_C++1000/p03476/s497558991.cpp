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
using pi = pair<int,int>;

signed main(){
	int q; cin>>q;
	vector<ll> vec(100100);
	rep(i,1,100100){
		vec[i]=vec[i-1];
		if(i%2==0)continue;
		bool ok=true;
		if(i==1)ok=false;
		for(ll j=2;j*j<=i;j++){
			if(i%j==0){
				ok=false;
				break;
			}
		}
		ll k=(i+1)/2;
		if(k==1)ok=false;
		for(ll j=2;j*j<=k;++j){
			if(k%j==0){
				ok=false;
				break;
			}
		}
		if(ok)vec[i]++;
	}
	while(q--){
		ll l,r; cin>>l>>r;
		cout<<vec[r]-vec[l-1]<<endl;
	}
	
	
	return 0;
}