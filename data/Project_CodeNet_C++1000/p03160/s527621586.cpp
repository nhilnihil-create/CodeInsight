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
int ara4[30], ara5[30];
int dp[N];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ara[i];
	}
	for (int i = 0; i <=n; i++) dp[i] = inf;
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		if (i + 1 < n) dp[i + 1] = min(dp[i + 1], dp[i] + abs(ara[i] - ara[i + 1]));
		if (i + 2 < n) dp[i + 2] = min(dp[i + 2], dp[i] + abs(ara[i] - ara[i + 2]));
	}
	cout << dp[n - 1] << "\n";
}