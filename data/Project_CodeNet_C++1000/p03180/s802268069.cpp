#include "bits/stdc++.h"
using namespace std;
#define int long long

int n;
const int MXN = 20;
int a[MXN][MXN];
int sc[1<<20];
int f;
int dp[1<<20];

int best(int mask) {
	// mask 1-bits are alr taken
	if (mask == f) return 0;
	if (dp[mask] != -1) return dp[mask];
	int o = f - mask;
	int b = 0;
	for (int t=o; t; t=(t-1)&o) {
		b = max(b, best(mask | t) + sc[t]);
	}
	return dp[mask] = b;
}

signed main() {
	
	for (int i=0; i<(1<<20); i++) dp[i] = -1;
	
	cin >> n;
	
	f = (1 << n) - 1;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int mask=0; mask<(1<<n); mask++) {
		int t = 0;
		for (int i=0; i<n; i++) {
			if (mask & (1 << i)) {
				for (int j=i+1; j<n; j++) {
					if (mask & (1 << j)) {
						t += a[i][j];
					}
				}	
			}
		}
		sc[mask] = t;
	}
	
	cout << best(0) << endl;
	
	
}
