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
int main() { // 問題文はしっかり読め!!!
	int n;
	cin >> n;
	vector<P<int>> a(n), b(n);
	rep(i, n) {
		cin >> a[i].first >> a[i].second;
	}
	rep(i, n) {
		cin >> b[i].first >> b[i].second;
	}
	sort(all(a));
	sort(all(b));
	vector<bool> used(n, false);
	int ans = 0;
	rep(i, n) {
		int pos = -1;
		int mx = -1;
		rep(j, n) {
			if (used[j]) continue;
			if (a[j].first > b[i].first || a[j].second > b[i].second) continue;
			if (chmax(mx, a[j].second)) pos = j;
		}
		if (pos != -1) ans++, used[pos] = true;
	}
	cout << ans << endl;
	return 0;
}