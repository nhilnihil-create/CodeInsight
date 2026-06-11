#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 998244353;
const ll MAX = 1000000;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

//gcd,lcm,べき,二進展開
//組み合わせ、mod計算
//最短路問題、bit、union find

///////////////////////////

ll bin(ll n, ll i) {
	if (i == 0) { return n % 2; }
	else { return bin(n / 2, i - 1); }
}

	
int main() {

	ll n;

	cin >> n;

	ll a[MAX];

	
	repn(i, n) cin >> a[i];

	ll ans = 0;

	ll t[20] = {};

	ll fr = 0;
	ll bc = 0;

	while (fr < n) {
		bool b = 1;

		if (bc == n) { b = 0; }

		else {
			rep(i, 20) {
				if (bin(a[bc + 1], i) == 1 && t[i] == 1) { b = 0; }
			}
		}

		if (b == 1) {
			rep(i, 20) {
				if (bin(a[bc + 1], i) == 1) { t[i] = 1; }
			}
			bc++;
		}

		else {
			rep(i, 20) {
				if (bin(a[fr+1], i) == 1) { t[i] = 0; }
			}
			ans += bc - fr;
			fr++;
		}
	}

	cout << ans;

	
	system("PAUSE");
}