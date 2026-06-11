#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long int ll;
const int N = 1e4 + 100;
vector<ll> a(N) , b(N) , c(N);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<ll> ab , abc;

	ll x, y , z , k;
	cin >> x >> y >> z >> k;
	for (int i = 0; i < x; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < y; ++i) {
		cin >> b[i];
	}

	for (int i = 0; i < z; ++i) {
		cin >> c[i];
	}


	sort(a.begin(), a.begin() + x, greater<ll>());
	sort(b.begin(), b.begin() + y, greater<ll>());
	for (int i = 0; i < min(x, k); ++i) {
		for (int j = 0; j < min(y , k); ++j) {
			ab.pb(a[i] + b[j]);
		}
	}
	sort(ab.begin(), ab.end(), greater<ll>());

	ll sz = ab.size();
	for (int i = 0; i < min( sz, k); ++i ) {
		for (int j = 0; j < min(z , k); ++j) {
			abc.pb(ab[i] + c[j]);
		}
	}
	sort( abc.begin(), abc.end(), greater<ll>() );
	for (int i = 0; i < k; ++i) cout << abc[i] << "\n";

}

