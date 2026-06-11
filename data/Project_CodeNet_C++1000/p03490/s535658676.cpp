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

char in[8050];
vector <int> Vu[3];

int dp[8050];
bool isValid(int x, vector <int> Vu) {
	int s = 0;
	for (auto it : Vu) s += it;
	if (s % 2 != (x + 10000) % 2) return false;

	int v = (s - x) / 2;
	if (v < 0 || v > s) return false;

	int i, j;
	for (i = 0; i <= v; i++) dp[i] = 0;
	dp[0] = 1;
	for (auto it : Vu) {
		for (i = v; i >= it; i--) if (dp[i - it]) dp[i] = 1;
	}
	if (dp[v]) return true;
	return false;
}
int main() {
	scanf("%s", in);

	int X, Y, i;
	scanf("%d %d", &X, &Y);
	int d = 2, cur = 0;
	for (i = 0; in[i] != 0; i++) {
		if (in[i] == 'T') {
			if (cur != 0) Vu[d].push_back(cur);
			cur = 0;
			if (d == 0 || d == 2) d = 1;
			else d = 0;
		}
		else cur++;
	}
	if (cur) Vu[d].push_back(cur);
	if (Vu[2].size()) X -= Vu[2][0];

	if (!isValid(X, Vu[0])) return !printf("No\n");
	if (!isValid(Y, Vu[1])) return !printf("No\n");
	return !printf("Yes\n");
}