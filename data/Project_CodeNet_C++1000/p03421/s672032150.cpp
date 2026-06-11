#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 16;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll in[300050];

ll ans[300050];
int main() {
	ll N, A, B, i, j;
	scanf("%lld %lld %lld", &N, &A, &B);

	if (A + B - 1 <= N && N <= A*B);
	else return !printf("-1\n");

	N -= A + B - 1;
	ans[1] = B;
	for (i = 2; i <= A; i++) ans[i] = 1;

	for (i = 2; i <= A; i++) {
		ans[i] += min(N, B - 1);
		N -= min(N, B - 1);
	}

	ll cur = 0;
	for (i = 1; i <= A; i++) {
		ll st = cur + 1, en = cur + ans[i];
		for (j = en; j >= st; j--) printf("%lld ", j);
		cur += ans[i];
	}
	return !printf("\n");
}