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
const ll mod = (1e+9)+7;
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
ll p[1 << 17];
ll sum[1 << 17];
int n;
ll extgcd(ll a, ll b, ll& x, ll& y) {
	ll d = a;
	if (b != 0) {
		d = extgcd(b, a%b, y, x);
		y -= (a / b)*x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}
//aのmod mでの逆元を求める
ll mod_inverse(ll a) {
	ll x, y;
	extgcd(a, mod, x, y);
	return (mod + x % mod) % mod;
}
void init() {
	p[0] = 1;
	Rep(i,1, 1 << 17) {
		p[i] = p[i - 1] * i%mod;
	}
	sum[0] = 0;
	Rep(i, 1, 1 << 17) {
		sum[i] = sum[i - 1] + p[n] * mod_inverse(i);
		sum[i] %= mod;
	}
}
ll a[1<< 17];
int main(){
	cin >> n; init();
	rep(i, n) {
		cin >> a[i];
	}
	ll out = 0;
	rep(i, n) {
		ll times = sum[i + 1] + sum[n - i] - sum[1];
		times %= mod;
		out += a[i] * times;
		out %= mod;
	}
	cout << out << endl;
	return 0;
}