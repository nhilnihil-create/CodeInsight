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

	multiset<ll> ms;
	rep(i, 0, N) {
		ll l;
		cin >> l;
		ms.insert(l);
	}

	set<pair<ll, multiset<ll>>> st({ {0,ms} });

	ll ans = ll_max;
	for (auto itr = st.begin(); itr != st.end();itr++) {
		ms = itr->second;
		ll cnt = itr->first;
		N = ms.size();
		if (2<N && cnt < ans) {
			for (auto itr1 = ms.begin(); itr1 != ms.end(); itr1++) {
				auto itr2 = itr1; itr2++;
				while (itr2 != ms.end()) {
					auto itr3 = itr2; itr3++;
					while (itr3 != ms.end()) {
						ans = min(ans, cnt + abs(*itr1 - C) + abs(*itr2 - B) + abs(*itr3 - A));
						itr3++;
					}
					itr2++;
				}
			}
			auto itr1 = ms.begin();
			while(itr1!=ms.end()){
				ll val1 = *itr1;
				auto itr2 = itr1; itr2++;
				ms.erase(itr1);
				while (itr2 != ms.end()) {
					ll val2 = *itr2;
					ms.erase(itr2);
					auto itr_tmp=ms.insert(val1 + val2);
					st.insert({ cnt + 10,ms });
					ms.erase(itr_tmp);
					itr2 = ms.insert(val2);
					while (itr2 != ms.end() && *itr2 == val2) {
						itr2++;
					}
				}
				itr1 = ms.insert(val1);
				while (itr1 != ms.end() && *itr1 == val1) {
					itr1++;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
