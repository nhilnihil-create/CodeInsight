#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD = 1000000007;

int main(int, char**) {
	int n;
	cin >> n;
	vector<ll> A, B, C;
	
	for (int i=0; i<n; i++) {
		ll a; cin>>a; A.push_back(a);
	}
	for (int i=0; i<n; i++) {
		ll a; cin>>a; B.push_back(a);
	}
	for (int i=0; i<n; i++) {
		ll a; cin>>a; C.push_back(a);
	}
	
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());

	ll ans = 0;
	for (int i=0; i<n; i++) {
		ll b = B[i];
		auto aitr = lower_bound(A.begin(), A.end(), b);
		auto citr = upper_bound(C.begin(), C.end(), b);
		ll na = aitr - A.begin();
		ll nc = C.end() - citr;
		ans += na * nc;
	}
	cout << ans << endl;
	return 0;
}