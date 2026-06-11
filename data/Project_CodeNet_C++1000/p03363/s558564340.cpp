#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	int n;
	scanf("%d", &n);
	ll sm = 0;
	map <ll, int> las;
	las[0] = -1;
	vector <int> to(n, -1);
	rep(i, n) {
		int a; scanf("%d", &a);
		sm += a;
		if (las.find(sm) != las.end())
			to[i] = las[sm] + 1;
		las[sm] = i;
	}
	vector <ll> f(n);
	rep(i, n) if (~to[i]) f[i] = (to[i] ? f[to[i] - 1] : 0) + 1;
	ll ans = 0;
	rep(i, n) ans += f[i];
	printf("%lld\n", ans);
	return 0;
}
