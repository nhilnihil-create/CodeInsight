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

const int MX = 200005;

int A[MX], B[MX];
int chk[MX];
int N, K, Q;

int main()
{
	scanf("%d%d%d", &N, &K, &Q);
	for(int i = 1; i <= N; i++) scanf("%d", A+i);
	for(int i = 1; i <= N; i++) B[i] = i;
	sort(B+1, B+N+1, [](int l, int r){ return A[l] < A[r]; });
	chk[N+1] = 1;
	int ans = 1e9;
	for(int i = 1; i <= N; i++){
		vector<int> L, M;
		for(int i = 1; i <= N+1; i++){
			if(chk[i]){
				sort(L.begin(), L.end());
				for(int t = 0; t < (int)L.size() - K + 1; t++) M.push_back(L[t]);
				L.clear();
			}
			else L.push_back(A[i]);
		}
		sort(M.begin(), M.end());
		if(M.size() >= Q) ans = min(ans, M[Q-1] - M[0]);
		chk[B[i]] = 1;
	}
	printf("%d\n", ans);
}
