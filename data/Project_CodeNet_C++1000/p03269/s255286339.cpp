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

int main() {
	vector<pair<pii, int>> Va;
	
	int v = 1;
	for (int i = 1; i <= 12; i++) {
		Va.emplace_back(pii(i, i + 1), 0);
		Va.emplace_back(pii(i, i + 1), 1*v);
		Va.emplace_back(pii(i, i + 1), 2*v);
		v *= 3;
	}

	int N;
	scanf("%d", &N);
	
	int cur = 0;
	v = 1;
	for (int i = 1; i <= 13; i++) {
		int c = N % 3;
		for (int j = 1; j <= c; j++) {
			Va.emplace_back(pii(i, 14), cur);
			cur += v;
		}
		N /= 3;
		v *= 3;
	}

	printf("14 %d\n", (int)Va.size());
	for (auto it : Va) printf("%d %d %d\n", it.first.first, it.first.second, it.second);
	return 0;
}