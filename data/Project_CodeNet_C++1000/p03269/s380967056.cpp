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

const int MX = 100055;
const int MM = 1000000007;

vector<t3> G;

int main()
{
	int L, M = 1;
	scanf("%d", &L); L--;
	int n = 1;
	for(; (1<<n)-1 <= L; n++); n--;
	for(int i = 1; i <= n; i++){
		G.emplace_back(i, i+1, 0);
		G.emplace_back(i, i+1, 1<<i-1);
	}
	L -= (1<<n)-1; M += (1<<n) - 1;
	for(int i = n; i >= 0; i--){
		if(L >= (1<<i)){
			G.emplace_back(i+1, n+1, M);
			L -= 1<<i;
			M += 1<<i;
		}
	}
	printf("%d %d\n", n+1, G.size());
	for(t3 e : G){
		int a, b, c;
		tie(a, b, c) = e;
		printf("%d %d %d\n", a, b, c);
	}
}
