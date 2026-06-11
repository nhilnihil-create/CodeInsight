// Frog 1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
using namespace std;
const int G = 1000 * 100 + 10;
int a[G];
long long dp[G];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	long long m;
	dp[1] = abs(a[0] - a[1]);
	for (int i = 2; i < n; i++){
		m = 1000000000000;
		for (int  j = max(0,i-k); j < i; j++){
			m = min(m , dp[j] + abs(a[i] - a[j]));
		}
		dp[i] = m;
	}
	cout << dp[n-1] << endl;
	return 0;
}

