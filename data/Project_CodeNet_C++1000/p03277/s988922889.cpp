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
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
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

int IT_MAX = 1 << 19;
const ll MOD = 100000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int bit[200050];
void update(int p, int v) {
	for (; p <= 200020; p += p & (-p)) bit[p] += v;
}
int getsum(int p) {
	int rv = 0;
	for (; p; p -= p & (-p)) rv += bit[p];
	return rv;
}

int in[100050];
int u[100050];
int sum[100050];

int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	int st = 1, en = INF, mi, rv = INF;
	while (st <= en) {
		mi = (st + en) / 2;

		ll cnt = 0;
		memset(bit, 0, sizeof(bit));
		update(100010, 1);
		for (i = 1; i <= N; i++) {
			u[i] = 1;
			if (in[i] > mi) u[i] = -1;
			sum[i] = sum[i - 1] + u[i];

			cnt += getsum(100010 + sum[i] - 1);
			update(100010 + sum[i], 1);
		}

		ll cnt2 = (ll)N * (N + 1) / 2 - cnt;
		if (cnt > cnt2) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}
	return !printf("%d\n", rv);
}