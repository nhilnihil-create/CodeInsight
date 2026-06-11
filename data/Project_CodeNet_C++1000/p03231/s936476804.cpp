#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#define _USE_MATH_DEFINES
#include<math.h>
#include<cmath>
#include<ctime>
#include<map>
#include<typeinfo>
#define R(i, n) for(int i = 0;i < n; i++)
#define S(a) scanf("%d", &a)
#define S2(a, b) scanf("%d%d", &a, &b)
#define S3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define SL(a) scanf("%lld", &a)
#define SL2(a, b) scanf("%lld%lld", &a, &b)
#define SL3(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define SA(i, n, a) R(i, n) scanf("%d", &a[i])
#define SAL(i, n, a) R(i, n) scanf("%lld", &a[i])
#define SC(a) scanf("%c", &a)
#define P(a) printf("%d", a)
#define PL(a) printf("%lld", a)
#define PY printf("YES")
#define PN printf("NO")
#define Py printf("Yes")
#define Pn printf("No")
using namespace std;
using ll = long long;
using PR = pair<int, int>;
const ll MOD = 1e+9 + 7;
const int INF = 1e+9;
const double PI = acos(-1);

int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main() {
	int n, m;
	string s, t;
	S2(n, m);
	cin >> s >> t;
	ll lcm = (ll)n * m / gcd(n, m);
	map<ll, char> map;
	ll a = 1;
	int i = 0;
	while (a <= lcm) {
		map.insert(make_pair(a, s[i]));
		a += lcm / n;
		i++;
	}
	ll b = 1;
	i = 0;
	while(b <= lcm){
		if (map.find(b) != map.end()) {
			if (map[b] != t[i]) {
				P(-1);
				return 0;
			}
		}
		b += lcm / m;
		i++;
	}
	PL(lcm);
}