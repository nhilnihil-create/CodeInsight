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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
ll makes(ll t) {
	ll res = 0;
	ll sum = 0;
	for (int i = 31; i >= 0; i--) {
		ll j = (ll)1 << i;
		ll dif1 = abs(sum+j - t);
		ll dif2 = abs(sum - j - t);
		if (dif1 < dif2) {
			res += j;
			sum += j;
		}
		else {
			sum -= j;
		}
	}
	return res;
}

string move(ll a, ll b) {
	string res;
	ll t1 = makes(a), t2 = makes(b);
	rep(i, 32) {
		ll key = (ll)1 << i;
		if ((t1&key) && (t2&key)) {
			res.push_back('R');
		}
		else if (t1&key) {
			res.push_back('U');
		}
		else if (t2&key) {
			res.push_back('D');
		}
		else res.push_back('L');
	}
	return res;
}
LP v[1000];
int main() {
	int m = 32;
	int n; cin >> n;
	bool exi[2] = { false,false };
	rep(i, n) {
		ll x, y; cin >> x >> y;
		if ((x + y) % 2) {
			exi[1] = true;
		}
		else {
			y--;
			exi[0] = true;
		}
		v[i] = { x,y };
	}
	if (exi[0] && exi[1]) {
		cout << -1 << endl;
	}
	else {
		if (exi[0]) {
			m++;
		}
		cout << m << endl;
		if (exi[0])cout << "1 ";
		rep(i, 32) {
			ll ele = (ll)1 << i;
			if (i > 0)cout << " "; cout << ele;
		}
		cout << endl;
		rep(i, n) {
			string g;
			if (exi[0]) {
				g.push_back('U');
			}
			cout << g+move(v[i].first + v[i].second, v[i].first - v[i].second) << endl;
		}
	}
	return 0;
}
