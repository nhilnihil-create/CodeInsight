#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;
 
#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif
 
typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
 
const int C = 100010;
const int N = 200200;
ll a[N], b[N];
 
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
 
	int n;
	scanf("%d", &n);
	a[C]++;
	b[C]++;
	while(n--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l += C;
		r += C;
		a[l]++;
		b[r]++;
	}
	for (int i = N - 2; i >= 0; i--)
		a[i] += a[i + 1];
	for (int i = 1; i < N; i++)
		b[i] += b[i - 1];
	ll ans = 0;
	for (int i = 0; i < N - 1; i++)
		ans += min(b[i], a[i + 1]);
	printf("%lld\n", ans * 2);
 
	return 0;
}