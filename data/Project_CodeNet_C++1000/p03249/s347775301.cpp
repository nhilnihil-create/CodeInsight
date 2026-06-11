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

const int MX = 1<<19;
const int MM = 998244353;

map<ll, int> DB;
int P[MX], ad[MX], cnt[MX];
ll D[MX], E[MX];
int N;

vector<int> T[MX];

ll dfs(int x, int p, int lev = 0){
	ll tot = 0;
	for(int c : T[x]){
		tot += dfs(c, x, lev+1);
	}
	return tot + lev;
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%lld", D+i);
		DB[D[i]] = i;
	}
	for(int i = 1; i <= N; i++) ad[i] = i;
	sort(ad+1, ad+N+1, [](int l, int r){
		return D[l] > D[r];
	});

	for(int i = 1; i <= N; i++) cnt[i] = 1;
	for(int i = 1; i < N; i++){
		int c = ad[i];
		ll v = D[c] - (N - cnt[c]*2);
		if(DB.find(v) == DB.end()) return !printf("-1\n");
		P[c] = DB[v];
		cnt[P[c]] += cnt[c];
		
		T[P[c]].push_back(c);
	}
	int r = ad[N];

	if(D[r] != dfs(r, -1)) return !printf("-1\n");
	for(int i = 1; i <= N; i++){
		for(int c : T[i]) printf("%d %d\n", i, c);
	}
}
