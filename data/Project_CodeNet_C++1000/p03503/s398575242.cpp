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

#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repeq(i,s,e) for(ll i=s;i<=e;i++)


int main() {
	ll N;
	std::cin >> N;
	
	vll B(N,0);
	rep(i, 0, N) {
		ll F;
		ll d = 1;
		rep(j, 0, 5) {
			rep(k, 0, 2) {
				std::cin >> F;
				B[i] += d * F;
				d *= 2;
			}
		}
	}

	vector<vll> P(N, vll(11));
	rep(i, 0, N) {
		rep(j, 0, 11) {
			std::cin >> P[i][j];
		}
	}


	ll ans = -1e9;
	rep(i, 1, (1LL << 10)) {
		ll tmp = 0;
		rep(j, 0, N) {
			ll cnt = 0;
			ll ol = i & B[j];
			while (ol > 0) {
				if (ol % 2==1) {
					cnt++;
				}
				ol = ol >> 1LL;
			}
			tmp += P[j][cnt];
		}
		ans = max(ans, tmp);
	}

	std::cout << ans << endl;
	return 0;
}
