#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;
const double PI=acos(-1);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	ll a,b; cin>>a>>b;
	ll k; cin>>k;
	set<ll> ans;
	rep(i,a,min(b+1,a+k)){
		ans.insert(i);
	}
	per(i,b+1,max(b-k+1,a)){
		ans.insert(i);
	}
	for(auto i:ans){
		cout<<i<<endl;
	}
}