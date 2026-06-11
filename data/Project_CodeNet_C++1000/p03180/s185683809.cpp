#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define pii pair<int, int>
typedef long long ll;
using namespace std;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int OFF = (1 << 20);

int n;
int a[20][20];
ll cost[(1 << 16) + 5];
ll dp[(1 << 16) + 5];
vector<int> v;
int tren;

void rek(int x, int mask) {
	if (x == v.size()) {
		dp[tren] = max(dp[tren], dp[tren-mask]+cost[mask]);
		return;
	}
	
	rek(x+1, mask);
	rek(x+1, mask|(1 << v[x]));
}

int main () {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				if ((i&(1 << j)) > 0 && (i&(1 << k)) > 0) {
					cost[i] += a[j][k];
				}
			}
		}
	}
	
	for (int i = 0; i < (1 << n); i++) {
		v.clear();
		for (int j = 0; j < n; j++) {
			if ((i&(1 << j)) > 0) {
				v.push_back(j);
			}
		}
		
		tren = i;
		rek(0, 0);
	}
	
	cout << dp[(1 << n)-1];

	return 0;
}
