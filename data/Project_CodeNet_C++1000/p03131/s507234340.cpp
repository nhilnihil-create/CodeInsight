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
	ll k, a, b;
	cin >> k >> a >> b;
	if(a >= b-2){
		cout << k+1 << endl;
		return 0;
	}
	ll ans = a;
	k -= a-1;
	ll cnt = k/2;
	ans += cnt * (b - a);
	k %= 2;
	ans += k;
	cout << ans << endl;
	return 0;
}
