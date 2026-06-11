// Stones.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
const int G = 1000 * 100 + 10;
int a[G];
int dp[G];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = a[1]; i <= k; i++){
		int m = 3;
		int l = lower_bound(a + 1, a + n + 1, i) - a;
		for (int j = 1; j <= l; j++){
			if (a[j] > i || j == n+1) break;
			int t = (dp[i- a[j]]+1)% 2;
			if (t == 0) t = 2;
			m = min(m,t);
		}
		dp[i] = m;
	}
	if(dp[k] == 1) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}

