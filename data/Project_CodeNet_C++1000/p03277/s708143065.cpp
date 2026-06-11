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
const int MM = 1000000007;

int A[MX];
int N;

struct BIT{
	int t[MX*2];
	int read(int x){
		int r = 0;
		while(x) r += t[x], x -= x&-x;
		return r;
	}
	int update(int x, int v){
		while(x < MX*2) t[x] += v, x += x&-x;
	}
} tree;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", A+i);
	int s = 0, e = 1e9;
	while(s <= e){
		int m = (s+e) / 2;
		for(int i = 0; i < MX*2; i++) tree.t[i] = 0;
		int pr = 0;
		ll tot = 0;
		
		for(int i = 1; i <= N; i++){
			tree.update(N+pr, 1);
			pr += A[i] >= m? 1 : -1;
			tot += tree.read(N+pr);
		}
		tot = (ll)N*(N+1)/2 - tot;
		if(tot >= (ll)N*(N+1)/2/2+1) e = m-1;
		else s = m+1;
	}swap(s, e);
	printf("%d\n", s);
}
