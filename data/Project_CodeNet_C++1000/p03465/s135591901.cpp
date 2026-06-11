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

int n;
int a[2005];
bitset <4000005> bs;

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	bs.set(0);
	int sm = 0;
	rep(i, n) bs |= bs << a[i], sm += a[i];
	int ans = (sm + 1) >> 1;
	while (!bs.test(ans)) ++ ans;
	printf("%d\n", ans);
	return 0;
}
