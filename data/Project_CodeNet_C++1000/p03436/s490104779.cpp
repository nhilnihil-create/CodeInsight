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

	vector<string> s(H);
	vector<vector<bool>> isVisited(H, vector<bool>(W, false));
	ll cnt_balck = 0;
	rep(i, 0, H) {
		std::cin >> s[i];
		rep(j, 0, W) {
			if (s[i][j] == '#') {
				cnt_balck++;
				isVisited[i][j] = true;
			}
		}
	}

	const vector<pair<ll, ll>> mov = { {1,0},{0,1},{-1,0},{0,-1} };

	queue<pair<ll, ll>> q;
	q.push({ 0LL,0LL });
	isVisited[0][0] = true;
	ll cnt_white = 1;
	while (!q.empty()) {
		cnt_white++;
		queue<pair<ll, ll>> r;
		while (!q.empty()) {
			auto h = q.front().first;
			auto w = q.front().second;
			q.pop();
			rep(i, 0, 4) {
				auto next_h = h + mov[i].first;
				auto next_w = w + mov[i].second;
				if (next_h == H - 1 && next_w == W - 1) {
					std::cout << H * W - cnt_white - cnt_balck << endl;
					return 0;
				}
				else if (0 <= next_h && next_h < H && 0 <= next_w && next_w < W && !isVisited[next_h][next_w]) {
					r.push({ next_h,next_w });
					isVisited[next_h][next_w] = true;
				}
			}
		}
		q = r;
	}

	std::cout << -1 << endl;


	return 0;
}
