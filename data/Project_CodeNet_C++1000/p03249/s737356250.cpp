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

map <ll, ll> Msz;

map <ll, ll> Mch;

vector <int> son[100050];
ll dep[100050];
ll sz[100050];
ll par[100050];
void DFS(int n) {
	sz[n] = 1;
	for (auto it : son[n]) {
		par[it] = n;
		dep[it] = dep[n] + 1;
		DFS(it);
		sz[n] += sz[it];
	}
}

ll in[100050];
ll oin[100050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
		Mch[in[i]] = i;
		Msz[in[i]] = 1;
		oin[i] = in[i];
	}

	sort(in + 1, in + N + 1);
	for (i = N; i > 1; i--) {
		ll t = Msz[in[i]];
		if (2 * t - N >= 0) return !printf("-1\n");

		ll p = in[i] + (2 * t - N);
		if (!Msz.count(p)) return !printf("-1\n");
		Msz[p] += t;

		son[Mch[p]].push_back(Mch[in[i]]);
	}

	int r = Mch[in[1]];
	DFS(r);

	ll s = 0;
	for (i = 1; i <= N; i++) {
		if (sz[i] == 0) return !printf("-1\n");
		s += dep[i];
	}

	if (s != oin[r]) return !printf("-1\n");

	for (i = 1; i <= N; i++) {
		if (i == r) continue;
		if (oin[i] - oin[par[i]] != N - 2 * sz[i]) return !printf("-1\n");
	}

	for (i = 1; i <= N; i++) {
		if (i == r) continue;
		printf("%lld %d\n", par[i], i);
	}
	return 0;
}