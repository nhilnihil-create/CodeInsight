// Vacation.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
using namespace std;
const int G = 1000 * 100 + 10;
int a[G][3];
long long dp[G][3];

int maxx(int x, int y, int z) {
	int max = x;
	if (y > max) max = y;
	if (z > max) max = z;
	return max;
}

int main()
{
	int n;
	cin >> n;
	for (int  i = 0; i < n; i++){
		for (int j = 0; j < 3; j++){
			cin >> a[i][j];
		}
	}
	dp[0][0] = a[0][0];
	dp[0][1] = a[0][1];
	dp[0][2] = a[0][2];
	for (int  i = 1; i < n; i++){
		dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i][0];
		dp[i][1] = max(dp[i-1][2], dp[i-1][0]) + a[i][1];
		dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + a[i][2];
	}
	cout << maxx(dp[n-1][0], dp[n-1][1], dp[n-1][2]) << endl;
	return 0;
}

