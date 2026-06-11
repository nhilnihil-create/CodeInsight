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
	vector<ll> v(n);
	rep(i,n) cin >> v[i];
	vector<ll> pre(n);
	vector<ll> suf(n);
	pre[0] = v[0];
	suf[n-1] = v[n-1];

	rep(i,n-1) {
		pre[i+1] = gcd(pre[i], v[i+1]);
		suf[n-1-i-1] = gcd(suf[n-1-i], v[n-1-i-1]);
	}

	ll ans = max(pre[n-2], suf[1]);
	for (int i = 1; i < n-1; i++) {
		ans = max(ans, gcd(pre[i-1], suf[i+1]));
	}
	cout << ans << endl;
}