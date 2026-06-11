#include <cmath>
#include <cstdio>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <stdio.h>
#include <functional>
#include <chrono>
using namespace std;

#define rep(i,s,n) for(ll i=s;i<(n);++i)
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll INF = (1LL << 60);
constexpr ll MAX_INF = 9223372036854775807;
constexpr ll MOD = (1e9 + 7);
//constexpr ll MOD = (998244353);

using vl = vector<ll>;
using vvl = vector<vector<ll>>;

template<class T>
vector<vector<T>> vvt(T init, ll m, ll n) {
	vector<vector<T>> ans = vector<vector<T>>(m, vector<T>(n, init));
	return move(ans);
}

template<class T>
vector<T> vt(T init, ll n) {
	vector<T> ans = vector<T>(n, init);
	return move(ans);
}

template<class T>
T maxVec(vector<T>& v) {
	T ans = -INF;
	rep(i, 0, v.size()) {
		ans = max(ans, v[i]);
	}
	return ans;
}

// 素数判定
bool judge(ll n) {
	for (ll i = 2; i * i <= n; i++) if (n %= i)return false;
	return true;
}


template <class C>
void print(const C & c, std::ostream & os = std::cout)
{
	std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, ", "));
	os << std::endl;
}
/*
ll count(ll n,ll r) {
	ll ans = 0,check = 1;
	rep(i,0, r) {
		if ((n & check) > 0) {
			ans++;
		}
		check = check << 1;
	}
	return ans;
}
*/
bool sortreverse(ll a, ll b) {
	return a > b;
}


ll kiriage(ll a, ll b) {
	if (a % b == 0)return a / b;
	return a / b + 1;
}

ll n, m, t, q, s,k,h,w;

void warshall_floyd(ll v_num,vector<vector<long long>> &d) {
	for (long long k = 0; k < v_num; k++) {       // 経由する頂点
		for (long long i = 0; i < v_num; i++) {    // 始点
			for (long long j = 0; j < v_num; j++) {  // 終点
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

ll findIndex(vl& vec, ll num) {
	rep(i, 0, vec.size()) {
		if (vec[i] == num)return i;
	}
	return -1;
}

int main() {
	cin >> n >> k;
	vector<pll> xy(n);
	vl x(n), y(n);
	rep(i, 0, n) {
		cin >> h >> w;
		xy[i] = pll{ h,w };
		x[i] = h; y[i] = w;
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	vvl zahyo(n, vl(n, 0)), dp(n + 1, vl(n + 1, 0));
	rep(i, 0, n) {
		ll xi, yi;
		xi = findIndex(x, xy[i].first);
		yi = findIndex(y, xy[i].second);
		zahyo[xi][yi] += 1;
	}
	rep(i, 0, n) {
		rep(j, 0, n) {
			dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + zahyo[i][j];
		}
	}
	ll ans = MAX_INF;

	rep(i, 0, n) {
		rep(j, 0, n) {
			rep(o, i+1, n) {
				rep(l, j+1, n) {
					ll kazu = dp[o + 1][l + 1] - dp[i][l + 1] - dp[o + 1][j] + dp[i][j];
					if (kazu >= k) {
						//printf("%lld %lld %lld %lld\n", i, j,k,l);
						ll menseki = (x[o] - x[i]) * (y[l] - y[j]);
						ans = min(ans, menseki);
					}
				}
			}
		}
	}
	printf("%lld\n", ans);
}