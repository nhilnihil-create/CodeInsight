#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

template<class T> inline bool chmin(T &a, T b){
	if(a > b){a = b; return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a < b){a = b; return true;}
	return false;
}

int dp[100005];

int main() {
	int n;
	cin >> n;
	vector<int> six, nine;
	int fs = 6;
	int fn = 9;
	while(fs <= n) {
		six.pb(fs);
		fs *= 6;
	}
	while(fn <= n) {
		nine.pb(fn);
		fn *= 9;
	}
	rep(i, n+1) dp[i] = INF;
	dp[0] = 0;
	repl(i, 1, n+1) {
		chmin(dp[i], dp[i-1] + 1);
		for(int x : six) {
			if(i - x < 0) break;
			chmin(dp[i], dp[i - x] + 1);
		}
		for(int x : nine) {
			if(i - x < 0) break;
			chmin(dp[i], dp[i - x] + 1);
		}
	}
	cout << dp[n] << endl;
    return 0;
}
