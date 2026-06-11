#include "bits/stdc++.h"
using namespace std;

//39
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	vector<int> pref(n);
	vector<int> suff(n);
	pref[0] = v[0];
	suff[n - 1] = v[n - 1];
	for (int i = 1; i < n; ++i) {
		pref[i] = __gcd(v[i],pref[i - 1]);
		suff[n - i - 1] = __gcd(v[n - i - 1],suff[n - i]);
	}
	int ans  = 0;
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			ans = max(ans,suff[i + 1]);
		}else if (i == n - 1) {
			ans = max(ans,pref[i - 1]);
		}else {
			ans = max(ans,__gcd(pref[i - 1],suff[i + 1]));
		}
	}
	cout << ans;
}
