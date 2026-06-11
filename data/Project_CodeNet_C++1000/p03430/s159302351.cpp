#define _CRT_SECURE_NO_WARNINGS
#include <iostream>	
#include <time.h>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <map>
#include <algorithm>
#include <queue>
#include <set>
#include <time.h>
#include <assert.h>
#include <sstream>
//#include <unordered_map>
#include <bitset>
#include <utility>
#include <iomanip>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <math.h>
#include <cmath>
#include <complex>
#ifdef MYDEF
#include "inc.h"
#endif
using namespace std;
typedef long long ll;
typedef complex<double> point;
 
int n, k;
char s[330];
int dp[330][330][330];
int calc(int i, int j, int rem) {
	if(i >= j)
		return i == j;
	int &ret = dp[i][j][rem];
	if(~ret)
		return ret;
	ret = max(calc(i + 1, j, rem), calc(i, j - 1, rem));
	if(s[i] == s[j])
		ret = max(ret, 2 + calc(i + 1, j - 1, rem));
	else if(rem)
	  ret = max(ret, 2 + calc(i + 1, j - 1, rem - 1));
	return ret;
}
 
int main() {
#ifdef MYDEF
	// sandstone
	HEAD
		freopen("a.txt", "r", stdin);
	//freopen("a.txt", "w", stdout);
	decTime;
#endif
 
	scanf("%s%d", s, &k);
	n = strlen(s);
	memset(dp, -1, sizeof dp);
	printf("%d\n", calc(0, n - 1, k));
 
 
#ifdef MYDEF
	printTime;
#endif
	return 0;
}