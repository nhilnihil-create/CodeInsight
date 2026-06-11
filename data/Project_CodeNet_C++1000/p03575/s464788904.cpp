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
	ll N, M;
	std::cin >> N >> M;

	map<ll,vector<ll>> edge;
	vector<ll> s(M), g(M);
	rep(i, 0, M) {
		std::cin >> s[i] >> g[i];
		edge[s[i]].push_back(g[i]);
		edge[g[i]].push_back(s[i]);
	}


	ll ans = M;
	rep(i, 0, M) {
		stack<pair<ll, ll>> st;
		vector<bool> isVisited(N+1, false);
		isVisited[s[i]] = true;
		st.push({ g[i], s[i] });

		while (!st.empty()) {
			ll pre = st.top().first;
			ll cur = st.top().second;
			isVisited[cur] = true;
			st.pop();
			
			rep(j, 0, edge[cur].size()) {
				if (pre != edge[cur][j]) {
					if (!isVisited[edge[cur][j]]) {
						if (edge[cur][j] == g[i]) {
							ans--;
							st = stack<pair<ll, ll>>{};
							break;
						}
						else {
							st.push({ cur,edge[cur][j] });
						}
						
					}
				}
			}
		}
	}
	std::cout << ans << endl;

	return 0;
}
