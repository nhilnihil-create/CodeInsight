#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define fore(i,a) for(auto &i:a)

typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1 << 30;
const ll INFL = 1LL << 60;
const ll mod = 1000000007;


vector<int> v[200005];

int main() {
	
	int n;
	cin >> n;
	VI c(n);
	REP(i, n)cin >> c[i];
	VI d;
	REP(i, n - 1) {
		if (c[i] != c[i + 1]) {
			d.push_back(c[i]);
		}
	}
	if (d.size() == 0) {
		d.push_back(c[n - 1]);
	}
	else {
		if (c[n - 1] != d[d.size() - 1]) {
			d.push_back(c[n - 1]);
		}
	}

	int m = d.size();

	VLL dp(m, 1);
	v[d[0]].push_back(0);

	FOR(i, 1, m) {
		ll a = 0;
		if (v[d[i]].size() != 0) {
			a = dp[v[d[i]][v[d[i]].size() - 1]];
		}
		dp[i] = dp[i - 1] + a;
		dp[i] %= mod;
		v[d[i]].push_back(i);
	}

	cout << dp[m - 1] << endl;


}