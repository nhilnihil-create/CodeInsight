#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;
using P = pair<ll, ll>;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
using Graph = VV;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Inf = (1 << 30);
ll inf = (1LL << 60);
const int MOD = 1e9 + 7;
int main() {
	ll n;
	cin >> n;
	/*
	rep(i, n) {
		int I = i + 1;
		if (n % I == n / I) cout << n / I << " " << I << endl;
	}
	cout << endl;
	*/
	if (n == 2) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 0;
	for (ll i = 1; i * i < n; i++) {
		ll N = n - i;
		if (N % i == 0) {
			ll tmp = N / i;
			if(n / tmp == i) ans += tmp;
		}
	}
	cout << ans << endl;
	return 0;
}