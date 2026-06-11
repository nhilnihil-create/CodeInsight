#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<ll>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	vector<ll>sig(n);
	for (int i = 0; i < n; i++) {
		if (i == 0)sig.at(0) = a.at(0);
		else sig.at(i) = sig.at(i-1) + a.at(i);
	}
	sig.push_back(0);
	sort(sig.begin(), sig.end());
	ll ans = 1;
	ll tmp = sig.at(0);
	vector<ll>cmb;
	for (int i = 1; i < n+1; i++) {
		if (sig.at(i) == tmp)ans++;
		else {
			cmb.push_back(ans);
			ans = 1;
			tmp = sig.at(i);
		}
	}
	cmb.push_back(ans);
	ans = 0;
	for (int i = 0; i < cmb.size(); i++) {
		if (cmb.at(i) >= 2)ans += cmb.at(i) * (cmb.at(i) - 1) / 2;
	}
	cout << ans << endl;
	/*
	1,3,-4,2,2,-2
	sig = 0,1,4,0,2,4,2
	sort sig=0,0,1,2,2,4,4
	cmb = 2,1,2,2
	*/
}