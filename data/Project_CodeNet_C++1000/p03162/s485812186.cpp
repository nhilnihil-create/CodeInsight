#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define isLeap(x) ((x % 400 == 0) || (x % 100 ? x % 4 == 0 : false))
#define FAST ios_base::sync_with_stdio(0), cin.tie(0)
#define LCM(a, b) (a / __gcd(a, b)) * b;
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define fr(m,n,c) for(int i = m; i < n; i+=c)
const int N = 1e5+3;
int ara[N+2];
pair<int, int> pp[N];
vector<int> vv[4*N];
set<int> st;
map<ll, ll> mp;
int ara1[N + 3], ara2[N + 3], ara3[N + 3];
int dp[N+3][3];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ara1[i] >> ara2[i] >> ara3[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 0) {
				if (j == 0) dp[i][j] = ara1[i];
				else if (j == 1) dp[i][j] = ara2[i];
				else dp[i][j] = ara3[i];
			}
			else {
				for (int k = 0; k < 3; k++) {
					if (j == k) continue;
					else if (j == 0) dp[i][j] = max(dp[i][j], dp[i - 1][k] + ara1[i]);
					else if (j == 1) dp[i][j] = max(dp[i][j], dp[i - 1][k] + ara2[i]);
					else dp[i][j] = max(dp[i][j], dp[i - 1][k] + ara3[i]);
				}
			}
		}
	}
	int maxi = 0;
	for (int i = 0; i < 3; i++) {
		maxi = max(dp[n - 1][i], maxi);
	}
	cout << maxi << "\n";
}