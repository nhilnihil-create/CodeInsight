#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
	ll n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	string t;
	cin >> t;
	ll l = lcm(n,m);
	ll x = l / n;
	ll y = l / m;
	for (ll i = 0; i < m; i++) {
		if ((i * y) % x != 0) continue;
		if (t[i] != s[(i * y) / x]) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << l << endl;
}