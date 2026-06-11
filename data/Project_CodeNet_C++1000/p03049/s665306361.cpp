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
int main() {
	ll n, a = 0, b = 0, f = 0, c = 0;
	cin >> n;
	rep(i, 0, n) {
		string s;
		cin >> s;
		rep(i2, 0, s.size() - 1) {
			if (s[i2] == 'A' && s[i2 + 1] == 'B')c++;
		}
		if (s.back() == 'A')a++;
		if (s.front() == 'B')b++;
		if ((s.back() == 'A') && (s.front() == 'B'))f++;
	}
	//printf("a:%lld b:%lld c:%lld f:%lld\n", a, b, c, f);
	printf("%lld\n", min(a, b) - (a == b && a == f && f > 0) + c);
	return 0;
}
