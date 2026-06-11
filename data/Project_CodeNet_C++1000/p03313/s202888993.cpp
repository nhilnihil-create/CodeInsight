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

typedef unsigned int uint;
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

const int MX = 1<<18;

pii D[MX];
int A[MX];

int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 0; i < 1<<N; i++){
		scanf("%d", A+i);
		D[i] = pii(A[i], -1);
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 1<<N; j++){
			if(j&1<<i) continue;
			pii u = D[j], v = D[j|1<<i], w;
			if(u.first > v.first) w = pii(u.first, max(u.second, v.first));
			else w = pii(v.first, max(v.second, u.first));
			D[j|1<<i] = w;
		}
	}
	int ans = 0;
	for(int i = 1; i < 1<<N; i++){
		ans = max(ans, D[i].first + D[i].second);
		printf("%d\n", ans);
	}
}
