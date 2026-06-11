#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define int long long

bool same(int n) {
	string a = to_string(n);
	for(int i = 1; i < a.length(); ++i) {
		if (a[i] == a[i-1]) continue;
		else return false;
	}
	return true;
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m; cin >> m;
	if (same(m)) {
		cout << m;
		return 0;
	}
	else {
		++m;
		while(!same(m)) {
			++m;
		}
	}
	cout << m;
}