#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define int long long
#define pb push_back
#define pi pair <int, int> 

int n, y;
int32_t main() {
	cin >> n >> y;
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= n; ++j) {
			int k = n - i - j;
			if (10000*i + 5000*j + 1000*k == y && k >= 0) {
				cout << i << ' ' << j << ' ' << k;
				return 0;
			}
		}
	}
	cout << "-1 -1 -1";
}