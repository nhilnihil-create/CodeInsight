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
signed main(){
	ll k,a,b; cin>>k>>a>>b;
	if(k<=a || b-a<=1){
		cout<<k+1<<endl;
		return 0;
	}
	ll ans=1;
	ans+=a-1;
	k-=a-1;
	ans+=(k/2)*(b-a);
	ans+=k%2;
	cout<<ans<<endl;
	


	
	return 0;
}