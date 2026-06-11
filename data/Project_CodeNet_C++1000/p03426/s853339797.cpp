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
int mdist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}
int main() {
	int h, w, d;
	cin >> h >> w >> d;
	VV a(h, V(w));
	vector<P<int>> nums(h * w + 1);
	rep(i, h) rep(j, w) {
		cin >> a[i][j];
		nums[a[i][j]] = make_pair(i, j);
	}
	VL dist(h * w + 1, 0);  // 次元を圧縮できるなら圧縮しよう！
	for (int i = d + 1; i <= h * w; i++) {
		dist[i] = dist[i - d] + mdist(nums[i - d].first, nums[i - d].second, nums[i].first, nums[i].second);
		// dの倍数であるという制約をうまく使うと1次元に圧縮できる
		// 複雑にしてもいいけどバグらせるな
	}
	int q;
	cin >> q;
	rep(qqqqq, q) {
		ll a, b;
		cin >> a >> b;
		cout << dist[b] - dist[a] << endl;
	}
	return 0;
}