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
ll a[100000], b[100000];
int main() {
	int n; cin >> n;
	rep(i, n) {
		cin >> a[i] >> b[i];
	}
	sort(a, a + n,greater<ll>()); sort(b, b + n);
	ll out = 0;
	rep(i, 2) {
		ll sum = 0;
		int chk = i;
		int cnt = 0;
		ll now = 0;
		bool f = false;
		int memo = 1e+7;
		while (cnt < n&&cnt<memo) {
			if (chk % 2) {
				if (now-b[cnt / 2] < 0) {
					f = true; memo = 2 * (cnt / 2) + 3; cnt++; chk = 1 - chk; continue;
				}
				sum += now-b[cnt / 2];
				now = b[cnt / 2];		
			}
			else {
				if (a[cnt / 2]-now < 0) {
					f = true; memo = 2 * (cnt / 2) + 3; cnt++; chk = 1 - chk; continue;
				}
				sum += a[cnt / 2] - now;
				now = a[cnt / 2];
			}
			chk = 1 - chk;
			cnt++;
		}
		sum += abs(now);
		out = max(out, sum);
	}
	cout << out << endl;
	return 0;
}