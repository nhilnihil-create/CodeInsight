
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

	if(b-a <= 2){
		cout << k+1 << endl;
	}
	else{
		ll ans = a;	// aまでビスケット叩く

		int t = (k-a+1) / 2;
		ans += (b-a) * t;

		if((k-a+1) & 1) ans++; //最後奇数なら

		cout << ans << endl;
	}

	return 0;
}
