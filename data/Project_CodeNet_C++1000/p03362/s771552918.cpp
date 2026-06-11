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
	std::cin >> N;

	// 5個とって合成数にするには5の倍数を考えるべき？？
	// とりあえずやってみる。

	ll cnt = 0;
	vector<ll> debug;
	vector<bool> is_pnum(55556, true);
	repeq(i, 2, 55555) {
		if (cnt < N && is_pnum[i]) {
			if (i % 5 == 1) {
				cnt++;
				std::cout << i << " ";
				debug.push_back(i);
			}
			for (ll j = i + i; j <= 55555; j += i) {
				is_pnum[j] = false;
			}
		}
	}
	std::cout << endl;

	// 実験
	/*
	stack<tuple<ll, ll, ll>> st;
	st.push({ 0,0,0 });
	while (!st.empty()) {
		auto cur = st.top();
		st.pop();
		if (get<0>(cur) < 4) {
			for (ll i = get<2>(cur); i < N; i++) {
				auto tmp = cur;
				get<0>(tmp)++;
				get<1>(tmp) += debug[i];
				get<2>(tmp) = i + 1;
				st.push(tmp);
			}
		}
		else {
			for (ll i = get<2>(cur); i < N; i++) {
				std::cout << get<1>(cur) + debug[i] << " " << IsPrimeNumber(get<1>(cur) + debug[i]) << endl;
			}
		}
	}
	*/

	return 0;
}
