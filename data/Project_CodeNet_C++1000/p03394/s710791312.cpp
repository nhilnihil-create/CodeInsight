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
 
int IT_MAX = 1 << 17;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first
 
int main() {
	int N;
	scanf("%d", &N);
 
	if (N == 3) return !printf("2 5 63\n");
	if (N == 4) return !printf("2 5 20 63\n");
	if (N == 5) return !printf("2 3 4 6 9\n");
	if (N == 6) return !printf("2 3 4 6 9 12\n");
	if (N == 7) return !printf("2 3 4 6 8 9 10\n");
	
	int x = N / 8;
	for (int i = 0; i < x; i++) printf("%d %d %d %d %d %d %d %d ", i * 12 + 2, i * 12 + 3, i * 12 + 4, i * 12 + 6, i * 12 + 8, i * 12 + 9, i * 12 + 10, i * 12 + 12);
 
	int t = x * 12;
	if (N % 8 == 0);
	else if (N % 8 <= 2) {
		printf("%d ", t + 6);
		if (N % 8 == 2) printf("%d ", t + 12);
	}
	else if (N % 8 <= 4) {
		printf("%d %d %d ", t + 3, t + 6, t + 9);
		if (N % 8 == 4) printf("%d ", t + 12);
	}
	else if (N % 8 <= 6) {
		printf("%d %d %d %d %d ", t + 2, t + 3, t + 4, t + 6, t + 9);
		if (N % 8 == 6) printf("%d ", t + 12);
	}
	else printf("%d %d %d %d %d %d %d ", t + 2, t + 3, t + 4, t + 6, t + 8, t + 9, t + 10);
	return !printf("\n");
}