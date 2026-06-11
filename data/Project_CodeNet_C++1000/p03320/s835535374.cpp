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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll getv(ll x) {
	ll t = x, s = 0;
	while (t) {
		s += t % 10;
		t /= 10;
	}
	return s;
}
int main() {
	vector <ll> Vl;

	ll i, j, k;
	for (i = 1; i <= 8; i++) Vl.push_back(i);

	ll cur = 9;
	for (i = 1; i <= 15; i++) {
		Vl.push_back(cur);
		for (j = 1;; j++) {
			if (j % 10 == 9) continue;
			if (j >= getv(j) + 9 * i) break;
			Vl.push_back((cur + 1) * j + cur);
		}
		cur = cur * 10 + 9;
	}
	sort(all(Vl));


	int N;
	scanf("%d", &N);
	for (i = 0; i < N; i++) printf("%lld\n", Vl[i]);
	return 0;
}