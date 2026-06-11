#include <iostream>
#include <iomanip>
#include<math.h>
#include<list>
#include <algorithm>
#include<set>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include <numeric>
#include <queue>
#include <sstream>
#include <bitset>
#include<stack>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using sll = set<long long>;
const long long ll_max = 9223372036854775807;
const long long ll_min = -9223372036854775807;
const int int_max = 2147483647;

template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T>
map<T, T> getPrimeFactor(T n) {
	map<T, T> res;
	for (T i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			res[i] ++;
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}

template<typename T>
bool IsPrimeNumber(T num)
{
	if (num <= 2) return true;
	else if (num % 2 == 0) return false;

	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

// 繰り返し二乗法
ll pow2(ll n, ll p, ll mod) {
	if (p == 0 || n == 1) {
		return 1;
	}
	else {
		ll ret = pow2(n * n % mod, p / 2, mod);
		if (p % 2 == 1) {
			ret *= n;
		}
		return ret % mod;
	}
}


#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repeq(i,s,e) for(ll i=s;i<=e;i++)

int main() {
	ll N;
	cin >> N;
	map<string, ll> dic_blue;
	rep(i, 0, N) {
		string str;
		cin >> str;
		dic_blue[str]++;
	}

	ll M;
	cin >> M;
	map<string, ll> dic_red;
	rep(i, 0, M) {
		string str;
		cin >> str;
		dic_red[str]++;
	}

	ll ans = 0;
	for (auto x : dic_blue) {
		auto y = dic_red.find(x.first);
		if (y == dic_red.end()) {
			ans = max(ans,x.second);
		}
		else {
			if (x.second > y->second) {
				ans = max(ans,x.second - y->second);
			}
		}
	}

	cout << ans << endl;
	return 0;

}
