#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<complex>
#include<math.h>
#include<queue>
#include <functional>
#include<time.h>
#include <stack>
#include<iomanip>
#include<unordered_map>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define sort(s) sort(s.begin(),s.end())
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<a>>
#define UF  UnionFind
#define rt (a); return (a); 
#define Pint pair<int,int>
#define Pll pair<ll,ll>
#define keta(a)  fixed << setprecision(a)
constexpr auto INF = 1000000000;
constexpr auto mod = 1000000007;
ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (b == 0)return a;
	return gcd(b, a % b);
}

hei(ll) seg;
void update(int k,ll x) {
	seg[k] = x;
	while (k > 1) {
		k -= 1;
		k /= 2;
		seg[k] = gcd(seg[k * 2 + 1], seg[k * 2 + 2]);
   }
}
ll query(int a, int b, int k, int l, int r) {
	if (b <= l || r <= a)return 0;
	if (a <= l && b >= r)return seg[k];
	ll v1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
	ll v2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
	return gcd(v1, v2);
}
int main() {
	int n;
	cin >> n;
	int x = 1;
	while (x < n)x *= 2;
	seg.resize(x*2-1);
	rep(i, 0, n) {
		ll a;
		cin >> a;
		update(x - 1 + i, a);
	}
	ll ans = 0;
	rep(i, 0, n) {
		if (i == 0) {
			ans = max(ans, query(1, n, 0, 0, x));
		}
		else if (i == n - 1) {
			ans = max(ans, query(0, n - 1, 0, 0, x));
		}
		else {
			ll a = query(0, i, 0, 0, x);
			ll b = query(i + 1, n, 0, 0, x);
			ans = max(ans, gcd(a, b));
		}
	}
	cout << ans << endl;
	return 0;
}
