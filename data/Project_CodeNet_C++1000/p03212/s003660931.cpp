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
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
//ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
ll p, c, limit;
int flag;
int dfs(ll n) {
	if (n > limit)return 0;
	p = n, flag = 0;
	while (p) {
		if (p % 10 == 3)flag |= 1;
		if (p % 10 == 5)flag |= 2;
		if (p % 10 == 7)flag |= 4;
		p /= 10;
	}
	if (flag == 7)c++;
	dfs(n * 10 + 3);
	dfs(n * 10 + 5);
	dfs(n * 10 + 7);
}
int main() {
	ll n;
	cin >> n;
	limit = n;
	dfs(0);
	printf("%lld\n", c);
	return 0;
}
