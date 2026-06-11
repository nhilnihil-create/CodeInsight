#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[200005][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	rep(i, 200005) rep(j, 2) dp[i][j] = 0;
	dp[0][0] = (s[0] != '.');
	dp[0][1] = (s[0] != '#');
	repn(i, 1, n){
		dp[i][0] = dp[i - 1][0] + (s[i] != '.');
		dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + (s[i] != '#');
	}
	cout << min(dp[n - 1][1], dp[n - 1][0]) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
