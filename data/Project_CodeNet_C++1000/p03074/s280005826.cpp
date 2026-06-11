#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<V>;
using VVV = vector<VV>;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
template<class T> using VE = vector<T>;
template<class T> using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
int main() {
	int n, k; string s;
	cin >> n >> k >> s;
	VE<P<int>> info;
	info.push_back(make_pair(1, 0));
	rep(i, n) {
		if (info[info.size() - 1].first == s[i] - '0') info[info.size() - 1].second++;
		else info.push_back(make_pair(s[i] - '0', 1));
	}
	rep1(i, info.size() - 1) info[i].second += info[i - 1].second;
	int ans = 0;
	for (int i = 0; i < info.size(); i += 2) {
		int Pos = i + 2 * k;
		chmin(Pos, (int)info.size() - 1);
		int prev = i == 0 ? 0 : info[i - 1].second;
		chmax(ans, info[Pos].second - prev);
	}
	cout << ans << endl;
	return 0;
}