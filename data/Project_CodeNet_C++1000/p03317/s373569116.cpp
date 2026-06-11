#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll long long

int main() {
	int n,k;

	//入力
	cin >> n >> k;
	vector<ll> a(n);
	rep(i,n) {
		cin >> a[i];
	}

	//答え
	int ans = 1 + ceil((double)(n-k) / (k-1));

	//答え
	std::cout << ans << endl;
}
