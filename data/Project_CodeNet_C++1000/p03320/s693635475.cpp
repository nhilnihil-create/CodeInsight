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

int main()
{
	vector<pll> L;
	ll mul = 1, i;
	while(mul <= 1e15){
		for(i = mul/10-1; i <= mul; i += max(mul/1000000, 1ll)){
			if(i <= 0 || i == mul/10-1) continue;
			ll cur = i, t = 0;
			while(cur) t += cur%10, cur /= 10;
			pll p = pll(i, t);
			while(L.size() && (ll)L.back().first * p.second > (ll)L.back().second * p.first) L.pop_back();
			L.push_back(p);
		}
		mul *= 10;
	}

	int K;
	scanf("%d", &K);
	ll cur = 2, m = 1;
	for(int i = 1; i <= K; i++) printf("%lld\n", L[i].first);
}
