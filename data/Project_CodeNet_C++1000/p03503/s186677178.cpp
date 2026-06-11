#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<deque>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<iostream>
#include <bitset>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
#define vec_unique(_a) _a.erase(std::unique(all(_a)), _a.end());
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
//ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
const int mod = 1000000007;
int main() {
	int n, v;
	cin >> n;
	vector<int> f(n);
	vector<vector<int>>p(n, vector<int>(11));
	rep(i, 0, n) {
		rep(i2, 0, 10) {
			cin >> v;
			f[i] <<= 1;
			f[i] |= v;
		}
	}
	rep(i, 0, n) {
		rep(i2, 0, 11) {
			cin >> p[i][i2];
		}
	}
	int M = -INF, t;
	rep(i, 1, 1 << 10) {
		t = -INF;
		rep(i2, 0, n) {
			if (t == -INF)t = 0;
			t += p[i2][bitset<32>(f[i2] & i).count()];
		}
		M = max(t, M);
	}
	printf("%d\n", M);
	return 0;
}
