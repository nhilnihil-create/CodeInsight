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
	int n;
	cin >> n;
	vector<int> v(n);
	rep(i,n) cin >> v[i];
	vector<ll> l(n), r(n);
	l[0] = v[0];
	rep(i,n-1) {
		l[i+1] = gcd(l[i], v[i+1]);
	}
	reverse(ALL(v));
	r[0] = v[0];
	rep(i,n-1) {
		r[i+1] = gcd(r[i], v[i+1]);
	}
	reverse(ALL(r));

	ll mx = 1;
	for (int i = 1; i < n-1; i++) {
		ll x = l[i-1];
		ll y = r[i+1];
		mx = max(mx, gcd(x, y));
	}
	mx = max(mx, r[1]);
	mx = max(mx, l[n-2]);
	cout << mx << endl;
}