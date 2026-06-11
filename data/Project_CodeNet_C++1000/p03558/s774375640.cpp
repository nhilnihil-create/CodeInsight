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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int dis[1000050];
priority_queue <pii, vector<pii>, greater<pii>> Hx;
int main() {
	int N, i;
	scanf("%d", &N);
	
	memset(dis, 0x3f, sizeof(dis));
	for (i = 1; i <= 9; i++) {
		dis[N*i] = 0;
		Hx.emplace(0, N*i);
	}
	while (!Hx.empty()) {
		pii u = Hx.top();
		Hx.pop();
		if (dis[u.second] != u.first) continue;
		for (i = 0; i < 10; i++) {
			int t = N * i + u.second;
			if (dis[t / 10] > u.first + t % 10) {
				dis[t / 10] = u.first + t % 10;
				Hx.emplace(dis[t / 10], t / 10);
			}
		}
	}
	return !printf("%d\n", dis[0]);
}