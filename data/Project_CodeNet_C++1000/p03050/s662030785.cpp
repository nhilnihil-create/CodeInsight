#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <deque>
#include <queue>
#include <functional>
//#include <boost/multiprecision/cpp_int.hpp>

#define rep(i, n) for(int i = 0; i < n; ++i)
#define REP(i, m, n) for(int i = m; i < n; ++i)
#define rrep(i,n) for(int i = n; i >= 0; --i)
#define RREP(i, m, n) for(int i = n; i >= m; --i)
#define llrep(i, n) for(ll i = 0; i < n; ++i)
#define llREP(i, m, n) for(ll i = m; i < n; ++i)
#define llrrep(i,n) for(ll i = n; i >= 0; --i)
#define llRREP(i, m, n) for(ll i = n; i >= m; --i)

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
using pil = std::pair<int, long long>;
using pli = std::pair<long long, int>;
using plpii = std::pair<long long, std::pair<int, int>>;
using pdd = std::pair<double, double>;

const long long INF = 1000000000000000001;
const long long _MOD = 1000000007;
const long long MOD = 998244353;
const int ALPHABET = 27;
const double pi = 3.14159265358979;

using namespace std;
//namespace mp = boost::multiprecision;

template<typename T>
constexpr std::vector<std::pair<T, T>> primeFactorization(T number) noexcept {
	std::vector<std::pair<T, T>> primeFactors;
	T quotient = number;
	for (T i = 2; i * i <= quotient; ++i) {
		if (quotient % i == 0) {
			T prime = i, power = 1;

			quotient /= i;
			while (quotient % i == 0) {
				++power;
				quotient /= i;
			}

			primeFactors.push_back(std::pair<T, T>(prime, power));
		}
	}
	if (quotient != 1) primeFactors.push_back(std::pair<T, T>(quotient, 1));

	return primeFactors;
}

template<typename T>
constexpr int countDivisor(std::vector<std::pair<T, T>> primeFactors) noexcept {
	int counter = 1;
	for (int i = 0; i < primeFactors.size(); ++i) {
		counter *= (primeFactors[i].second + 1);
	}

	return counter;
}

template<typename T>
constexpr std::vector<T> findDivisor(T number) noexcept {
	std::vector<std::pair<T, T>> primeFactors = primeFactorization(number);

	std::vector<T> divisor(countDivisor(primeFactors));
	divisor[0] = 1;

	int counter = 1;
	for (int i = 0; i < primeFactors.size(); ++i) {
		int currentSize = counter;
		for (int j = 1; j <= primeFactors[i].second; ++j) {
			T x = 1;
			for (int k = 0; k < j; ++k) {
				x *= primeFactors[i].first;
			}

			for (int k = 0; k < currentSize; ++k) {
				divisor[counter + k] = divisor[k] * x;
			}
			counter += currentSize;
		}
	}
	sort(divisor.begin(), divisor.end());

	return divisor;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;

	vector<ll> divisor = findDivisor(n);

	ll ans = 0;
	rep(i, divisor.size()-1) {
		if (divisor[i] >= divisor[divisor.size() - 1 - i] - 1) break;
		ans += divisor[divisor.size() - 1 - i] - 1;
	}

	cout << ans << "\n";

	return 0;
}
