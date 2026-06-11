#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>
#include <bitset>

using namespace std;

const int MAXN = 1 << 11;

int n,sum;
int a[MAXN];

bitset<MAXN * MAXN> B;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	B[0] = 1;
	for (int i = 1;i <= n;i++)
		B = B << a[i] | B;
	for (int i = (sum + 1) / 2;i <= sum;i++)
		if (B[i])
		{
			cout << i << endl;
			return 0;
		}
	return 0;
}
