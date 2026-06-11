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
pair< pair<int, int>, int> p[1002];

bool cmp(pair< pair<int, int>, int> x, pair< pair<int, int>, int> y) {
	return x.X.X+x.X.Y < y.X.X+y.X.Y;
}

ll dp[20002];

int main () {

	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i].X.X >> p[i].X.Y >> p[i].Y;
	sort(p, p + n, cmp);
	
	ll maxi = 0;
	for (int i = 0; i < n; i++) {
		for (int j = p[i].X.Y; j >= 0; j--) {
			dp[j+p[i].X.X] = max(dp[j+p[i].X.X], dp[j]+p[i].Y);
		
			maxi = max(maxi, dp[j+p[i].X.X]);
		}
	}
	
	cout << maxi;

	return 0;
}