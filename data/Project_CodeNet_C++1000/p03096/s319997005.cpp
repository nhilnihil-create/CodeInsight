#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repA(i, a, n) for(int i = a; i <= (n); ++i)
#define repD(i, a, n) for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a) memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll MOD = 1e9 + 7;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n; cin >> n;
	vi c(n); rep(i,n) cin >> c[i];
	map <int, int> ma;
	vll dp(n); dp[0] = 1; ma[c[0]] = 1;
	repA(i,1,n-1){
		if(c[i] == c[i-1]){
			dp[i] = dp[i-1];
			continue;
		}
		dp[i] = (dp[i-1] + ma[c[i]])%MOD;
		ma[c[i]] = (ma[c[i]] + dp[i-1])%MOD;
	}
	cout << dp[n-1] << endl;
	return 0;
}

