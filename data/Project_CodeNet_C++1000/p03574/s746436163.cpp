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
int dx[] = { -1,0,1,-1,0,1,-1,0,1 };
int dy[] = { -1,-1,-1,0,0,0,1,1,1 };
int main() {
	int h, w;
	cin >> h >> w;
	VE<string> s(h);
	rep(i, h) {
		cin >> s[i];
	}
	VV ans(h, V(w, 0));
	auto exist = [&](int y, int x) {
		return 0 <= x && x < w && 0 <= y && y < h;
	};
	rep(i, h) rep(j, w) {
		if (s[i][j] == '#') {
			rep(dir, 9) {
				if (exist(i + dy[dir], j + dx[dir])) ans[i + dy[dir]][j + dx[dir]]++;
			}
		}
	}
	rep(i, h) {
		rep(j, w) {
			if (s[i][j] == '#') cout << '#';
			else cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}