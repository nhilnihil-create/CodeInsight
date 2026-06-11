#include <bits/stdc++.h>

#define ll long long
#define MAX 1000003
#define MOD 1000000007
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector< int>>
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
#define FOR(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define all(v) (v).begin(),(v).end()
#define INF (int)1e9
#define EPS 1e-9

using namespace std;

const int MAXN = 1e5+5;
int dp [MAXN];

void solve(vi &a, int n){
	dp[0] = 0;
	dp[1] = abs(a[1] - a[0]);

	rep(i, 2, n){
		dp[i] = min(dp[i-1] + abs(a[i-1] - a[i]), dp[i-2] + abs(a[i-2] - a[i]));
	}

	cout << dp[n-1] << "\n";
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a(n);
	FOR(i, n)	cin >> a[i];

	solve(a, n);	
	
return 0;
}