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

pii D[MX];

int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d%d", &D[i].first, &D[i].second);
	for(int i = 1; i <= N; i++){
		if((D[i].first + D[i].second + D[1].first + D[1].second) % 2 != 0) return !printf("-1\n");
	}
	int ch = 0;
	if((D[1].first + D[1].second) % 2 == 0) ch = 1;
	
	if(ch) printf("32\n1 ");
	else printf("31\n");
	for(int i = 30; i >= 0; i--) printf("%d ", 1<<i);
	printf("\n");

	for(int i = 1; i <= N; i++){
		int dx[4] = {-1, 0, 1, 0};
		int dy[4] = {0, -1, 0, 1};
		char s[5] = "LDRU";
		pii cur = pii(0, 0);
		if(ch) printf("R"), cur = pii(1, 0);
		for(int m = 30; m >= 0; m--){
			ll dist = 1e18;
			char ans;
			pii x;
			for(int d = 0; d < 4; d++){
				pii nxt = pii(cur.first + dx[d] * (1<<m), cur.second + dy[d] * (1<<m));
				ll t = abs((ll)nxt.first - D[i].first) + abs((ll)nxt.second - D[i].second);
				if(dist > t) dist = t, ans = s[d], x = nxt;
			}
			cur = x; printf("%c", ans);
		}
		printf("\n");
	}
}
