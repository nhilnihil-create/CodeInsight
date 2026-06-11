#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = (1e+9)+7;
const ll INF = (ll)1000000007 * 1000000007;
const double EPS = 1e-9;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int main() {
    int a[200000], b[200000],c[200000];
	queue<int>q;
	int n; cin >> n;
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> b[i];
	}
	rep(j, 29) {
		int m = 1 << j; int d = m << 1;
		rep(i, n) {
			c[i] = b[i] % d;
		}
		sort(c, c + n);
		int sum = 0;
		rep(i, n) {
			int x = a[i] % d;
			x = m - x;
			if (x > 0) {
				int le = lower_bound(c, c + n, x) - c;
				int ri = lower_bound(c, c + n, x + m) - c;
				sum += ri - le;
			}
			else {
				int le = lower_bound(c, c + n, x + d) - c;
				int ri = lower_bound(c, c + n, x + m) - c;
				ri += n;
				sum += ri - le;
			}
			sum %= 2;
		}
		if (sum)q.push(j);
	}
	int out = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		out += (1 << x);
	}
	cout << out << endl;
	return 0;
}