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
// const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
int main() { // 問題文はしっかり読め!!!
	int n, m;
	cin >> n >> m;
	V a(n);
	rep(i, n) {
		cin >> a[i];
	}
	ll ans = 0;
	rep(i, m + 1) { // 何回操作する？
		rep(j, min(i, n) + 1) { // 左からどれだけ取り出す？
			rep(k, min(i - j, n) + 1) { // 右からどれだけ取り出す？
				priority_queue<int, V, greater<int>> pq;
				vector<bool> find(n, false);
				ll tmp = 0;
				int out = i - (k + j);
				rep(R, j) {
					tmp += a[R];
					pq.push(a[R]);
					find[R] = true;
				}
				rep(L, k) {
					if (find[n - 1 - L]) {
						out += k - L - 1;
						break;
					}
					tmp += a[n - 1 - L];
					pq.push(a[n - 1 - L]);
					find[n - 1 - L] = true;
				}
				while (out && !pq.empty() && pq.top() < 0) {
					out--;
					tmp += abs(pq.top());
					pq.pop();
				}
				chmax(ans, tmp);
			}
		}
	}
	cout << ans << endl;
	return 0;
}