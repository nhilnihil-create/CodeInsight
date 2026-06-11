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

const int MX = 250005;

vector<pll> A[2][MX];
int D[MX];
int N;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", D+i);
	for(int t = 0; t < 2; t++){
		int m = 0;
		ll lsum = 0, rsum = 0;
		for(int i = 1; i <= N; i++){
			rsum += D[i];
			while(m+1 <= i && lsum + D[m+1] <= rsum - D[m+1]){
				lsum += D[m+1];
				rsum -= D[m+1];
				m++;
			}
			if(lsum == rsum) A[t][i].emplace_back(lsum, rsum);
			else{
				A[t][i].emplace_back(lsum, rsum);
				A[t][i].emplace_back(lsum + D[m+1], rsum - D[m+1]);
			}
		}
		reverse(D+1, D+N+1);
	}
	ll ans = 1e18;
	for(int i = 2; i <= N-2; i++){
		for(pll c1 : A[0][i]){
			for(pll c2 : A[1][N-i]){
				vector<ll> tp;
				tp.push_back(c1.first);
				tp.push_back(c1.second);
				tp.push_back(c2.first);
				tp.push_back(c2.second);
				sort(tp.begin(), tp.end());
				ans = min(ans, tp.back() - tp[0]);
			}
		}
	}
	printf("%lld\n", ans);
}
