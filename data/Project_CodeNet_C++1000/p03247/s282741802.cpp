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

ll myrem(ll x) {
	return (x % 2 + 2) % 2;
}

ll in[1050][2];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld %lld", &in[i][0], &in[i][1]);
	
	ll c = myrem(in[1][0] + in[1][1]);
	for (i = 2; i <= N; i++) if (myrem(in[i][0] + in[i][1]) != c) return !printf("-1\n");

	if (c == 1) {
		printf("33\n");
		for (ll i = 0; i <= 32; i++) printf("%lld ", 1ll << i);
		printf("\n");
	}
	else {
		printf("34\n1 ");
		for (ll i = 0; i <= 32; i++) printf("%lld ", 1ll << i);
		printf("\n");
	}

	for (i = 1; i <= N; i++) {
		ll x = in[i][0], y = in[i][1];
		x *= -1, y *= -1;

		if (c == 0) {
			printf("R");
			x++;
		}

		for (ll j = 0; j <= 31; j++) {
			if (x % 2) {
				if (myrem((x + 1) / 2) != myrem(y / 2)) {
					x++;
					printf("R");
				}
				else {
					x--;
					printf("L");
				}
			}
			else {
				if (myrem(x / 2) != myrem((y + 1) / 2)) {
					y++;
					printf("U");
				}
				else {
					y--;
					printf("D");
				}
			}
			x /= 2, y /= 2;
		}
		if (x == -1) printf("R");
		else if (x == 1) printf("L");
		else if (y == -1) printf("U");
		else printf("D");
		printf("\n");
	}
	return 0;
}