#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 305;

int n,ans;

char s[MAXN][MAXN];

bool check(int v)
{
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			if (s[i][(j + v) % n] != s[j][(i + v) % n])
				return 0;
	return 1;
}

int main()
{
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
		scanf("%s",s[i]);
	for (int i = 0;i < n;i++)
		if (check(i))
			ans += n;
	printf("%d\n",ans);
	return 0;
}