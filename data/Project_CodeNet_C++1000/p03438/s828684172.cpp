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
//ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
//ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
int main() {
	int N;
	ll S = 0, k = 0;
	scanf("%d", &N);
	vector<int> a(N), b(N);
	rep(i, 0, N)scanf("%d", &a[i]), S -= a[i];
	rep(i, 0, N)scanf("%d", &b[i]), S += b[i];
	rep(i, 0, N) {
		if (a[i] < b[i])k+=(b[i] - a[i] + 1) / 2;
	}
	//printf("%d %d %lld\n", k, k2, Sb - Sa);
	puts(k <= S ? "Yes" : "No");
	return 0;
}