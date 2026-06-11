#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		//UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>		//do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define ALL(u) (u).begin(),(u).end()

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

typedef pair<int, int> PII;

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

const int MR = 310;

char S[MR];

int dp[MR][MR][MR];

// key observation - max subsequence of S and rev(S) is the length of the longest palindromic subsequence of S
int go(int b, int e, int k)
{
	if (dp[b][e][k])
		return dp[b][e][k];
	if (b >= e)
		return 0;
	if (b == e - 1)
		return dp[b][e][k] = 1;

	if (b == e - 2)
	{
		if (S[b] == S[b + 1] || k)
			return dp[b][e][k] = 2;
		else
			return dp[b][e][k] = 1;
	}

	if (S[b] == S[e - 1])
		return 2 + go(b + 1, e - 1, k);

	return dp[b][e][k] = max(max(go(b + 1, e, k), go(b, e - 1, k)), k ? 2 + go(b + 1, e - 1, k - 1) : 0);
}

int main()
{
	int K;
	scanf("%s%d", S, &K);

	printf("%d\n", go(0, strlen(S), K));

	return 0;
}