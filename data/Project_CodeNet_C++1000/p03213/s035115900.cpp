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
template<class T> using pq = priority_queue<T>;
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
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -MOD * MOD;
const long double pi = 3.141592653589793;
int fact[101];
void pfact(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i) continue;
		while (x % i == 0) {
			fact[i]++;
			x /= i;
		}
	}
	if (x >= 2) fact[x]++;
}
int main() { // 問題文はしっかり読め!!!
	int n;
	cin >> n;
	rep1(i, n) {
		pfact(i);
	}
	V ni;
	V yon;
	V itiyonn;
	V niyonn;
	V nanayonn;
	set<pair<int, pair<int, int>>> st1; // p^4*q^4*r^2,75個はこれだけやと思ってた
	set<P<int>> st2; // p^14*q^4
	set<P<int>> st3; // p^24*q^3
	int ans74 = 0; // p^74
	REP(i, 2, 101) {
		if (fact[i] >= 2) ni.push_back(i);
		if (fact[i] >= 4) yon.push_back(i);
		if (fact[i] >= 14) itiyonn.push_back(i);
		if (fact[i] >= 24) niyonn.push_back(i);
		if (fact[i] >= 74) ans74++;
	}
	rep(i, ni.size()) {
		rep(j, yon.size()) {
			rep(k, yon.size()) {
				if (ni[i] != yon[j] && ni[i] != yon[k] && yon[j] != yon[k]) {
					int a = ni[i], b = yon[j], c = yon[k];
					if (b < c) swap(b, c);
					st1.insert(make_pair(a, make_pair(b, c)));
				}
			}
		}
	}
	rep(i, yon.size()) {
		rep(j, itiyonn.size()) {
			if (yon[i] != itiyonn[j]) {
				st2.insert(make_pair(yon[i], itiyonn[j]));
			}
		}
	}
	rep(i, ni.size()) {
		rep(j, niyonn.size()) {
			if (ni[i] != yon[j]) {
				st3.insert(make_pair(ni[i], yon[j]));
			}
		}
	}
	cout << st1.size() + st2.size() + st3.size() + ans74 << endl;
	return 0;
}