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
const ll MOD = 998244353;
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
ll dp[200001][3] = {};
ll dp2[200001][3][3] = {};
int main() {
	bool f = true;
	ll n, a, b; cin >> n >> a >> b;
	if (n >a*b||n<a+b-1) {
		cout << -1 << endl;
	}
	else {
		int rest = n; int now = 0;
		rep1(i, a) {
			if (rest - b >= a - i) {
				now = i * b;
				for (int j = i * b; j > (i - 1)*b; j--) {
					cout << j << " ";
				}
				rest -= b;
			}
			else if (rest == a - i+1) {
				rest--; now++;
				cout << now << " ";
			}
			else {
				int x = rest - (a - i);
				now += x;
				for (int j = now; j > now - x; j--) {
					cout << j << " ";
				}
				rest = a - i;
			}
		}
		cout << endl;
	}
	return 0;
}