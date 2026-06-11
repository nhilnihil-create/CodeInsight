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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);


void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), greater<int>());
	map<int, int> mp;
	rep(i, n)mp[a[i]]++; int ans = 0;
	per(j, 31) {
		int k = 1 << j;
		rep(i, n) {
			int x = a[i];
			if (x > k)continue;
			int r = k - x;
			if (x == r) {
				if (mp[x] >= 2) {
					ans ++; mp[x] -= 2;
				}
			}
			else {
				if (mp[x] > 0 && mp[r] > 0) {
					ans++; mp[x]--; mp[r]--;
				}
			}
		}
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}
