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
	ll H, W;
	std::cin >> H >> W;
	vector<vll> a(H, vll(W, 0));

	ll sum = 0;
	ll ll_input;
	queue < pair<pair<ll, ll>, pair<ll, ll>>> q;
	rep(i, 0, H) {
		rep(j, 0, W) {
			std::cin >> ll_input;
			a[i][j] += ll_input;
			if (i == H - 1 && j == W - 1) {
				break;
			}
			if (a[i][j] & 1) {
				if (i < H - 1) {
					q.push({ {i,j},{i + 1,j} });
					a[i + 1][j] ++;
				}
				else {
					q.push({ {i,j},{i,j + 1} });
					a[i][j + 1] ++;
				}
				a[i][j]--;
			}
		}
	}
	std::cout << q.size() << endl;
	while (!q.empty()) {
		std::cout << q.front().first.first+1 << " " << q.front().first.second+1 << " " << q.front().second.first+1 << " " << q.front().second.second+1 << endl;
		q.pop();
	}


	return 0;
}
