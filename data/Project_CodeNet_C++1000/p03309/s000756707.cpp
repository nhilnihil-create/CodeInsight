#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll long long

int main() {
	int n;

	//入力
	cin >> n;
	vector<ll> a(n);
	for (ll i=0;i<n;++i) {
		int m;
		cin >> m;
		a[i] = m - i-1;
	}
	//sort
	sort(a.begin(), a.end());

	//a[i]の中央値
	ll c = a[n / 2];

	//答え
	ll ans = 0;
	for (int i = 0;i < n;++i) {
		ans += abs(a[i] - c);
	}

	//答え
	std::cout << ans << endl;
}
