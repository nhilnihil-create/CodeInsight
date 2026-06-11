#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k, n) for (ll i = k; i < (ll)(n); ++i)
#define MAX 100010
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll ans, cnt;


int main() {
	ll R;
	cin >> R ;
	

	if (R < 1200) {
		cout << "ABC" << endl;
	}
	else if (R < 2800) {
		cout << "ARC" << endl;
	}
	else {
		cout << "AGC" << endl;
	}

	return 0;
}
