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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
char t[1 << 18], d[1 << 18];
 
int n, q; string s;
int sta(int x) {
	rep(i, q) {
		if (s[x] == t[i]) {
			if (d[i] == 'L')x--;
			else x++;
		}
		if (x < 0)return 1;
		else if (x >= n)return 2;
	}
	return 0;
}
void solve() {
	cin >> n >> q >> s;
	rep(i, q) {
		cin >> t[i] >> d[i];
	}
	int le = 0, ri = n;
	while (ri - le > 1) {
		int mid = (le + ri) / 2;
		if (sta(mid) == 1)le = mid;
		else ri = mid;
	}
	int cle = 0, cri = n;
	while (cri - cle > 1) {
		int mid = (cle + cri) / 2;
		if (sta(mid) == 2)cri = mid;
		else cle = mid;
	}
	int ans = cle - ri + 1;
	if (ans < 0)ans = 0;
	cout << ans << endl;
}
int main() {
	solve();
	//stop
	return 0;
}
