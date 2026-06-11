// Grid 1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
using namespace std;
const int G = 1000 + 10;
char a[G][G];
long long dp[G][G];

int main()
{
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			cin >> a[i][j];
		}
	}
	dp[0][0] = 1;
	for (int i = 1; i < w; i++){
		if (a[0][i] == '.'){
			dp[0][i] = dp[0][i-1];
			dp[0][i] %= 1000000007;
		}
	}
	for (int i = 1; i < h; i++){
		if (a[i][0] == '.'){
			dp[i][0] = dp[i-1][0];
			dp[i][0] %= 1000000007;
		}
	}
	for (int i = 1; i < h; i++){
		for (int j = 1; j < w; j++){
			if (a[i][j] == '.'){
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
				dp[i][j] %= 1000000007;
			}
		}
	}
	cout << dp[h-1][w-1] % 1000000007 << endl;
	return 0;
}

