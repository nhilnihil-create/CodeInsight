
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

int main() {

	ll k, a, b;
	cin >> k >> a >> b;

	if(a+1 >= b){
		cout << k+1 << endl;
		return 0;
	}

	ll ans = 1;
	for(ll i=1; i<=k; ++i){
		if(ans < a){
			ans = a;
			i = a-1;
		}
		else if(i == k){
			ans++;
		}
		else{
			int t = (k-i+1) / 2;
			ans += (b-a) * t;
			i += t * 2 - 1;
		}
	}

	cout << ans << endl;

	return 0;
}
