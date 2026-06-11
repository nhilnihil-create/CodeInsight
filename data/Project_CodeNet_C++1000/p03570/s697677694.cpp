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

int IT_MAX = 1 << 17;
ll MOD = 1000000007ll;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first
#define rep(i, n) for(int i=0;i<n;i++)
#define pb(x) push_back(x)

const int MX = 20005;

int dp[1<<26];

int main()
{
	string D;
	cin >> D;
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;

	int cur = 0;
	for(int t = 0; t < D.size(); t++){
		if(t+1 != D.size()){
			cur ^= 1<<D[t]-'a';
			for(int i = 0; i < 26; i++){
				dp[cur] = min(dp[cur], dp[cur^1<<i] + 1);
			}
		}
		else{
			cur ^= 1<<D[t]-'a';
			int ans = dp[cur] + 1;
			for(int i = 0; i < 26; i++){
				ans = min(ans, dp[cur^1<<i] + 1);
			}
			printf("%d\n", ans);
		}
	}
}
