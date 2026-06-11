#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ar array
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod = 1e9 + 7;
const ll inf = 2e9 + 5;
double PI = 3.14159265358979323846;


void solve() {

	int n, k;
	cin >> n >> k;
	vi a(n+1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vvi dp(n + 1, vi(k + 1, 0));

	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {

		vi pre(k+1,0);
		pre[0] = dp[i-1][0];
		for(int j = 1;j <=k;j++){
			pre[j] = (pre[j-1] + dp[i-1][j])%mod;
		}

		for (int j = 0; j <= k; j++) {
			// if I have j candies I can give ith child any candies from 0...j
			// say I give x to ith child then remaining can be divided
			// among i-1 children something like:
			// dp[i-1][j-x]+dp[i-1][j-x-1]+++dp[i-1][0] i,e prefix_sum(dp[i-1][0...j-x])
			int temp;
			if(j-a[i] > 0){
				temp = ((pre[j] - pre[j-a[i]-1])%mod+mod)%mod;
			} else{
				temp = pre[j];
			}
			dp[i][j] = temp;
		}
	}
	cout << dp[n][k];

}

int32_t main()
{
	IOS
	// int T; cin >> T; while (T--)
	solve();
	return 0;
}
