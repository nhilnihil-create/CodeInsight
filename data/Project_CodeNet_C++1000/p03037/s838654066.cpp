#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<cmath>
#include<numeric>
#include<iomanip>
#include<functional>
#include<cstdlib>
#include<queue>
#include<deque>
const double PI = acos(-1);
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
using ll =long long;
const int mod = 1000000007;
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

ll gcd(ll a, ll b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
};
//fixed << setprecision(2)
bool  Array_check(ll y, ll x,ll d,ll w) {
	if (x < 0 || x >= w || y<0 || y>=d) {
		return false;
	}
	else {
		return true;
	}
	
}

//小文字=大文字+32
int main() {
	ll n, m;
	cin >> n >> m;
	vector<ll>L(m), R(m);
	ll l = 1, r = n;
	rep(i, m) {
		cin >> L[i] >> R[i];

	}
	rep(i, m) {
		l = max(l, L[i]);
		r = min(R[i], r);

	}
	if ( r-l >= 0) {
		cout << r-l+1;
	}
	else {
		cout << 0;
	}
}
