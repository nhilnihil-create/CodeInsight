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
	rep(i,n) {
		cin >> a[i];
	}

	//
	int ans = 0;
	rep(i, n) {
		while (a[i] % 2 == 0) {
			a[i] /= 2;
			++ans;
		}
	}

	//答え
	std::cout << ans << endl;
}