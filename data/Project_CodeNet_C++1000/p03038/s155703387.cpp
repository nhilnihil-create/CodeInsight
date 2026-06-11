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
signed main(){
	ll n,m; cin>>n>>m;
	priority_queue<ll, vector<ll>, greater<ll>> q;
	rep(i,0,n){
		ll a; cin>>a;
		q.push(a);
	}
	vector<pl> vec(m);
	ll ans=0;
	rep(i,0,m)cin>>vec[i].second>>vec[i].first;
	sort(all(vec));
	for(int i=m-1;i>=0;--i){
		ll cnt=0;
		ll a=vec[i].first;
		ll b=vec[i].second;
		rep(j,0,b){
			ll k=q.top();
			if(a<=k)break;
			q.pop();
			q.push(a);
			cnt++;
		}
		if(cnt==0)break;
	}
	rep(i,0,n)ans+=q.top(),q.pop();
	cout<<ans<<endl;




	return 0;
}