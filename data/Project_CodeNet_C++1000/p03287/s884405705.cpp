#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n), sum_mod(n+1, 0);
	map<ll,ll> mp;
	ll ans = 0;
	rep(i,n){
		cin >> a[i];
		sum_mod[i+1] = (sum_mod[i] + a[i]) % m;
		if(sum_mod[i+1] == 0) ++ans;
		ans += mp[sum_mod[i+1]];
		mp[sum_mod[i+1]]++;
	}
	cout << ans << endl;
	return 0;
}