// dpj.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

//#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
double dp[310][310][310];
int n;
double dps(int i, int j, int k) {
	if (dp[i][j][k] != -1)return dp[i][j][k];
	if (i == 0 && j == 0 && k == 0)return 0.0;
	double ret = 0.0;
	if (i > 0)ret += dps(i - 1, j, k)*i;
	if (j > 0) ret += dps(i + 1, j - 1, k)*j;
	if (k > 0)ret += dps(i, j + 1, k - 1)*k;
	ret += n;
	ret *= 1.0 / (i + j + k);
	dp[i][j][k] = ret;
	return ret;
}
int main()
{
	cin >> n; // 皿の数

	int i=0;
	int j = 0;
	int k = 0;
	int a;
	for (int d = 0; d < n; d++)
	{
		cin >> a;
		if (a == 1) i++;
		if (a == 2) j++;
		if (a == 3) k++;
	}
	for (int is = 0; is < 310; is++) {
		for (int js = 0; js < 310; js++)
		{
			for (int ks = 0; ks < 310; ks++)
			{
				dp[is][js][ks] = -1;
			}
		}
	}
	double ans = dps(i, j, k);
	printf("%10.10f\n", ans);

}
