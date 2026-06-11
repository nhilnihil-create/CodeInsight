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
#include<functional>
#include<unordered_set>
#include<unordered_map>

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
	map<T, T> ret;
	for (T i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			ret[i] ++;
			n /= i;
		}
	}
	if (n != 1) ret[n] = 1;
	return ret;
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
	ll N, A, B, C;
	cin >> N >> A >> B >> C;

	vll l(N);
	rep(i, 0, N) {
		cin >> l[i];
	}
	sort(l.begin(), l.end());

	set<pair<ll, vll>> st({ {0,l} });
	ll cnter = 0;
	ll ans = ll_max;
	for (auto x:st) {
		cnter++;
		if (cnter > 10000) {
			cnter = 0;
		}
		l = x.second;
		ll cnt = x.first;
		N = l.size();
		if (2<N && cnt < ans) {
			rep(i, 0, N - 2) {
				rep(j, i + 1, N - 1) {
					rep(k, j + 1, N) {
						ans = min(ans, cnt + abs(l[i] - C) + abs(l[j] - B) + abs(l[k] - A));
					}
				}
			}
			rep(i, 1, (1LL << N)) {
				vll m;
				ll val = 0;
				ll num = -1;
				rep(j, 0, N) {
					if (i & (1LL << j)) {
						val += l[j];
						num++;
					}
					else {
						m.push_back(l[j]);
					}
				}
				if (num > 0) {
					m.push_back(val);
					sort(m.begin(), m.end());
					st.insert({ cnt + num * 10,m });
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
