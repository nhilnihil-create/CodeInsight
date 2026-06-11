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

	map<ll, ll> dic;
	dic[0] = 1;
	rep(i, 0, N) {
		ll a;
		std::cin >> a;
		dic[a]++;
	}

	if (dic[0] > 1 || dic[12] > 1) {
		std::cout << 0 << endl;
		return 0;
	}
	rep(i, 1, 12) {
		if (dic[i] > 2) {
			std::cout << 0 << endl;
			return 0;
		}
	}

	ll ans = 0;
	rep(i, 0, (1LL << 12)) {
		ll tmp = 9999;
		repeq(j, 0, 12) {
			if (dic[j]>0) {
				if (dic[j] > 1) {
					tmp = min(tmp, min(j + j, 24 - j - j));
				}
				vll a = { j,24 - j };
				repeq(k, j + 1, 12) {
					if (dic[k]>0) {
						vll b = { k,24 - k };
						if (dic[k] > 1) {
							tmp = min(tmp, min(k + k, 24 - k - k));
							if (dic[j] > 1) {
								rep(jj, 0, 2) {
									rep(kk, 0, 2) {
										tmp = min(tmp, min(abs(a[jj] - b[kk]), 24 - abs(a[jj] - b[kk])));
									}
								}
							}
							else{
								rep(kk, 0, 2) {
									tmp = min(tmp, min(abs(a[(bool)(i & (1LL << j))] - b[kk]), 24 - abs(a[(bool)(i & (1LL << j))] - b[kk])));
								}
							}
						}
						if (dic[j] > 1) {
							rep(jj, 0, 2) {
								tmp = min(tmp, min(abs(a[jj] - b[(bool)(i & (1LL << k))]), 24 - abs(a[jj] - b[(bool)(i & (1LL << k))])));
							}
						}
						else {
							tmp = min(tmp, min(abs(a[(bool)(i & (1LL << j))] - b[(bool)(i & (1LL << k))]), 24 - abs(a[(bool)(i & (1LL << j))] - b[(bool)(i & (1LL << k))])));
						}
					}
				}
			}
		}
		ans = max(ans, tmp);
	}


	std::cout << ans << endl;
	return 0;
}
