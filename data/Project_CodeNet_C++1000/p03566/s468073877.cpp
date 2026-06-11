#pragma comment(linker,"/STACK:36777216")

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <ctime>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())
#define ten(n) ((int)1e##n)
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;


template<class T> void chmin(T& a, const T& b) { if (a > b) a = b; }
template<class T> void chmax(T& a, const T& b) { if (a < b) a = b; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
ll mod_pow(ll a, ll n, ll mod) {
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }

int dp[2][210];

int main() {
    int n; cin>>n;
    vector<int> t(n),v(n);
    FOR(i,n) cin>>t[i];
    FOR(i,n) cin>>v[i];
    FOR(i,n) {
        t[i] *= 2;
        v[i] *= 2;
    }

    auto cr = dp[0], nt = dp[1];
    memset(dp, 0x8F, sizeof(dp));
    cr[0] = 0;
  FOR(i,n) {
        FOR(j, t[i]) {
            FOR(k, v[i]+1) if(cr[k] >= 0) {
                for (int nk = -1; nk <= 1; nk++) {
                  	int d = k + nk;
                  	if (d < 0 || d > v[i]) continue;
                    chmax(nt[d], cr[k] + k + d);
                }
            }
          swap(cr, nt);
            memset(nt, 0xCF, sizeof dp[0]);
        }
    }

    printf("%.10lf\n", cr[0] / 8.0);

	return 0;
}
