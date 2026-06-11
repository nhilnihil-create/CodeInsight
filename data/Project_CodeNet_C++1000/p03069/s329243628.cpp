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
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define INF 1LL << 60
#define MAX 1000000000

ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll power(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x *= x; p /= 2; } else { a *= x; p--; } }return a; }

int main() {
	int N, c = 0, ans = 0, sum = 0;
	vector<int> k;
	bool flag = false;
	scanf("%d", &N);
	ans = N;
	char* s = new char[N + 1];
	scanf("%s", s);
	while (*s) {
		if (*s == '#')flag = true;
		if (flag) {
			c++;
			if (*s != *(s + 1)) {
				k.push_back(c);
				if(k.size() % 2 == 0)sum += c;
				c = 0;
			}
		}
		s++;
	}
	ans = sum;
	//printf("%d\n", sum);
	rep(i, 0, k.size() / 2) {
		sum += k[i * 2] - k[i * 2 + 1];
		//printf("%d\n", sum);
		ans = min(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
}