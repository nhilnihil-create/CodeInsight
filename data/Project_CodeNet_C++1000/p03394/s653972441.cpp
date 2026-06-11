/**
 *    author:  otera    
**/
#include<iostream>
#include<string> 
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm> 
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

#define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
	int n; cin >> n;
	if(n == 3) {
		cout << "2 5 63\n";
	} else if(n == 4) {
		cout << "2 5 20 63\n";
	} else if(n == 5) {
		cout << "2 5 20 63 90\n";
	} else if(n == 6) {
		cout << "2 5 20 63 90 180\n";
	} else if(n == 7) {
		cout << "2 5 20 63 90 180 270\n";
	} else {
		rep(i, n / 8) {
			cout << 12 * i + 2 << " " << 12 * i + 3 << " " << 12 * i + 4 << " " << 12 * i + 6 << " " << 12 * i + 8 << " " << 12 * i + 9 << " " << 12 * i + 10 << " " << 12 * i + 12 << " ";
		}
		int m = n / 8;
		if(n % 8 == 0) {
			//
		} else if(n % 8 == 1) cout << 12 * m + 6 << endl;
		else if(n % 8 == 2) cout << 12 * m + 2 << " " << 12 * m + 4 << endl;
		else if(n % 8 == 3) cout << 12 * m + 2 << " " << 12 * m + 4 << " " << 12 * m + 6 << endl;
		else if(n % 8 == 4) cout << 12 * m + 2 << " " << 12 * m + 4 << " " << 12 * m + 6 << " " << 12 * m + 12 << endl;
		else if(n % 8 == 5) cout << 12 * m + 2 << " " << 12 * m + 4 << " " << 12 * m + 6 << " " << 12 * m + 8 << " " << 12 * m + 10 << endl;
		else if(n % 8 == 6) cout << 12 * m + 2 << " " << 12 * m + 4 << " " << 12 * m + 6 << " " << 12 * m + 8 << " " << 12 * m + 10 << " " << 12 * m + 12 << endl;
		else if(n % 8 == 7) cout << 12 * m + 2 << " " << 12 * m + 3 << " " << 12 * m + 4 << " " << 12 * m + 8 << " " << 12 * m + 9 << " " << 12 * m + 10 << " " << 12 * m + 12 << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}