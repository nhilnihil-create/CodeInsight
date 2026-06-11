#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include<iomanip> 
#include<cmath>  
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<bitset>
#include<map>
// #include<unordered_map>
#include<set>
// #include<unordered_set>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
using namespace std;
typedef long long ll;
#define repi(i,a,b) for(ll i = (ll)(a) ; i < (ll)(b) ; i++)
#define repd(i,a,b) for(ll i = (ll)(a) ; i > (ll)(b) ; i--)
#define rd(x) cin >> x
#define wr(x)  cout << x
#define wrln(x) cout << x << endl
#define wl() cout << endl
const ll MAX_10p5 = 100010;
const ll MAX_10p9 = 1000000010;
const ll MAX_10p18 = 1000000000000000010;
const ll MOD = 1000000007;
const ll m4x[4] = { 1,0,-1,0 };
const ll m4y[4] = { 0,1,0,-1 };
const ll m8x[8] = { 1,1,0,-1,-1,-1,0,1 };
const ll m8y[8] = { 0,1,1,1,0,-1,-1,-1 };
const ll m9x[9] = { 1,1,0,-1,-1,-1,0,1,0 };
const ll m9y[9] = { 0,1,1,1,0,-1,-1,-1,0 };

struct edge {
	ll from, to, cost;
	bool operator<(const edge& right) const {
		return cost < right.cost;
	}
};
struct point {
	ll x, y, idx;
	bool operator<(const point& right) const {
		return x == right.x ? y < right.y : x < right.x;
	}
};

template<typename T>
T minT(T a, T b) {
	if (a < b) return a;
	else return b;
}

template<typename T>
T maxT(T a, T b) {
	if (a > b) return a;
	else return b;
}

template<typename T>
T absT(T a) {
	if (a < 0) a *= -1;
	return a;
}

template<typename T>
T powT(T a, T x) {
	T res = 1;
	while (x > 0) {
		if (x & 1) res = res*a;
		a = a*a;
		x >>= 1;
	}
	return res;
}

ll StoLL(string str) {
	ll ret = 0, ini = 0;
	if (str[0] == '-') ini = 1;
	repi(i, ini, str.length()) {
		ret *= 10;
		ret += (ll)(str[i] - '0');
	}
	if (ini) ret *= -1;
	return ret;
}

///////////////////////////////////////////////////////////////////////////////////////

ll fill9(ll n, ll d) {
	repi(i, 0, d) {
		n /= 10;
	}
	repi(i, 0, d) {
		n *= 10;
		n += 9;
	}
	return n;
}

ll calcDSum(ll x) {
	ll ret = 0;
	while (x > 0) {
		ret += (x % 10);
		x /= 10;
	}
	return ret;
}

ll calcNAns(ll x) {
	ll ret = x, retS = calcDSum(x);

	ll t = x, d = 0;
	while (t > 0) {
		d++;
		t /= 10;
	}

	repi(i, 1, d + 1) {
		ll temp = fill9(x, i), tempS = calcDSum(temp);
		if (ret*tempS > temp*retS) {
			ret = temp, retS = tempS;
		}
	}
	return ret;
}

int main() {
	ll ans = 0, K;
	cin >> K;
	repi(i, 0, K) {
		ans = calcNAns(ans + 1);
		wrln(ans);
	}
	return 0;
}
