#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e18;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	ll ans = 0, mi = INF;
	bool same = true;
	rep(i,n){
		cin >> a[i] >> b[i];
		if(a[i] > b[i]) chmin(mi, b[i]);
		ans += a[i];
		if(b[i] != a[i]) same = false;
	}
	if(mi < INF) ans -= mi;
	if(same) ans = 0;
	cout << ans << endl;
	return 0;
}