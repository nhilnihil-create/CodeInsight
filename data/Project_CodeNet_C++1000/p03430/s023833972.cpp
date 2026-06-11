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

int IT_MAX = 1 << 20;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

pii operator-(pii l, pii r){ return pii(l.first - r.first, l.second - r.second); }
ll operator/(pii l, pii r){ return (ll)l.first * r.second - (ll)l.second * r.first; }
ll operator*(pii l, pii r){ return (ll)l.first * r.first + (ll)l.second * r.second; }

const int MX = 305;
char D[MX];
int T[MX][MX][MX];
int N, K;

int main()
{
	scanf("%s%d", D+1, &K);
	N = strlen(D+1);
	for(int i = 1; i <= N; i++) T[i][i][0] = 1;
	for(int i = 1; i < N; i++){
		for(int x = 1; x+i <= N; x++){
			int y = x+i;
			for(int k = 0; k <= K; k++){
				T[x][y][k] = max(T[x+1][y][k], T[x][y-1][k]);
				if( k ) T[x][y][k] = max(T[x+1][y-1][k-1] + 2, T[x][y][k]);
				if( D[x] == D[y] ) T[x][y][k] = max(T[x+1][y-1][k] + 2, T[x][y][k]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= K; i++) ans = max(ans, T[1][N][i]);
	printf("%d\n", ans);
}
