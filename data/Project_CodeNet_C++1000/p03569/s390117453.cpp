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
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
const ll mod = 1000000007;
int main() {
	int ans = 0;
	char str[100001], *s, *e;
	scanf("%s", str);
	s = str, e = s + strlen(s) - 1;
	while (s <= e) {
		//printf("s:%c e:%c\n", *s, *e);
		if (*s != *e) {
			if (*s == 'x')s++, ans++;
			else if (*e == 'x')e--, ans++;
			else {
				puts("-1");
				return 0;
			}
		}
		else s++, e--;
	}
	printf("%d\n", ans);
	return 0;
}
