#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
using pq = priority_queue<int>;
template<class T>
using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int under = (1 << 31);
int upper = under - 1;
ll UNDER = (1LL << 63);
ll UPPER = UNDER - 1;
const int MOD = 1e9 + 7;
const long double pi = 3.141592653589793;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	V count(27, 0);
	rep(i, n) {
		count[s[i] - 'a']++;
	}
	VVL dp(27, VL(27, 0)); // i番目までのアルファベットをj個ピックした時の部分列の個数
	dp[0][0] = 1;
	rep(i, 26) rep(j, 26) {
		dp[i + 1][j] += dp[i][j];
		dp[i + 1][j + 1] += dp[i][j] * count[i];
		dp[i + 1][j + 1] %= MOD;
	}
	ll ans = 0;
	rep1(i, 26) {
		ans += dp[26][i];
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}