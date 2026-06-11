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
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	dp[1] = abs(a[0] - a[1]);
	for (int i = 2; i < n; i++){
		dp[i] = min(dp[i-1] + abs(a[i] - a[i-1]),dp[i-2] + abs(a[i] - a[i-2]));
	}
	cout << dp[n-1] << endl;
	return 0;
}

