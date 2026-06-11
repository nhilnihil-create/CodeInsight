#include "bits/stdc++.h"
//#include "atcoder/all"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
//using namespace atcoder;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	sort(a.rbegin(), a.rend());
	ll ans = 0;
	rep(i,n){
		if(i%2 == 0) ans += a[i];
		else ans -= a[i];
	}
	cout << ans << endl;
	return 0;
}
