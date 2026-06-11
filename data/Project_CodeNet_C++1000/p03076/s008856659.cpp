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
	vl a(5);
	rep(i,0,5)cin>>a[i];
	ll ans=MOD;
	do{
		ll cnt=0;
		rep(i,0,5){
			if(i==4){
				cnt+=a[i];
			}
			else{
				ll k=(a[i]+10-1)/10;
				cnt+=k*10;
			}
		}
		chmin(ans,cnt);
	}while(next_permutation(all(a)));
	cout<<ans<<endl;
	return 0;
}