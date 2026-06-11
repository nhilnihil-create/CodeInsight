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

const int MX = 100005;

ll D[MX], V[MX];
ll A[2][MX], B[2][MX];

int main()
{
	ll N, C;
	scanf("%lld%lld", &N, &C);

	ll ans = 0;
	for(int i = 1; i <= N; i++) scanf("%lld%lld", D+i, V+i);
	for(int t = 0; t < 2; t++){
		for(int i = 1; i <= N; i++) A[t][i] = A[t][i-1] + V[i] - (D[i] - D[i-1]);
		for(int i = 1; i <= N; i++) A[t][i] = max(A[t][i-1], A[t][i]);
		for(int i = 1; i <= N; i++) B[t][i] = B[t][i-1] + V[i] - 2*(D[i] - D[i-1]);

		for(int i = 1; i <= N; i++) D[i] = C - D[i];
		reverse(D+1, D+N+1);
		reverse(V+1, V+N+1);
	}
	for(int i = 0; i <= N; i++){
		ans = max(ans, A[0][i] + B[1][N-i]);
		ans = max(ans, A[1][i] + B[0][N-i]);
	}
	printf("%lld\n", ans);
}
