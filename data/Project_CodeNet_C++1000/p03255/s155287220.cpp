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
#include <chrono>
#include <random>
#include <queue>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = (ll)1e18;
const int N = 200200;
ll ANS;
int n;
ll a[N];
ll prefSum[N];
ll X;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &X);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i < n; i++)
		prefSum[i + 1] = prefSum[i] + a[i];
	ANS = INF;
	for (int k = 1; k <= n; k++) {
		ll curAns = k * X;
		int r = n;
		curAns += 2 * (prefSum[r] - prefSum[r - k]);
		ll z = 1;
		while(r > 0) {
			z += 2;
			int l = max(0, r - k);
			ll sum = prefSum[r] - prefSum[l];
			if (2 * INF / z < sum) {
				curAns = INF;
				break;
			}
			curAns += sum * z;
			curAns = min(curAns, INF);
			r = l;
		}
		ANS = min(ANS, curAns);
	}


	ANS += n * X;
	printf("%lld\n", ANS);

	return 0;
}
