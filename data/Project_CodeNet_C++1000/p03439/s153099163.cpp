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
	ll s = 0;
	ll e = N - 1;
	string s1,s2;
	std::cout << 0 << endl;
	std::cin >> s1;
	if (s1 == "Vacant") {
		return 0;
	}
	ll idx = 0;
	while (true) {
		ll idx = (e - s+1) / 2+s;
		std::cout << idx << endl;
		std::cin >> s2;
		if (s2 == "Vacant") {
			return 0;
		}
		else if (((idx-s)&1&&s1!=s2)||(!((idx-s)&1)&& s1 == s2)) {
			s = idx;
			s1 = s2;
		}
		else {
			e = idx;
		}
	}
 
	return 0;
}