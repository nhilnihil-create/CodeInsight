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
	int n;
	cin >> n;
	int A = 0;
	int B = 0;
	int AB = 0;
	int ans = 0;
	rep(i, n) {
		string s;
		cin >> s;
		if (s[0] == 'B' && s[s.size() - 1] == 'A') AB++;
		else if (s[0] == 'B') B++;
		else if (s[s.size() - 1] == 'A') A++;
		rep(i, s.size() - 1) {
			if (s[i] == 'A' && s[i + 1] == 'B') ans++;
		}
	}
	// cout << A << endl << B << endl << AB << endl << ans << endl;
	if (!A && !B) {
		cout << ans + max(0, AB - 1) << endl;
		return 0;
	}
	cout << ans + min(A, B) + AB << endl;
	return 0;
}