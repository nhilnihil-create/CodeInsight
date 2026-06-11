#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

void solve() {
	int n;
	cin >> n;
	
	vi c(n);
	for(int i = 0; i < n; i++) cin >> c[i];
	
	vi prev(n);
	map<int, int> u;
	for(int i = 0; i < n; i++) {
		if(!u.count(c[i])) prev[i] = -1;
		else prev[i] = u[c[i]];
		u[c[i]] = i;
	}
	
	vi dp(n, 0);
	dp[0] = 1;
	for(int i = 1; i < n; i++) {
		(dp[i] = dp[i - 1] + (prev[i] == -1 || prev[i] == i - 1 ? 0 : dp[prev[i]])) %= P;
	}
	
	cout << dp[n - 1] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}