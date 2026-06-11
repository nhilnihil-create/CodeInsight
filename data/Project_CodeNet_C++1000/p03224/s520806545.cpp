#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 500 
int n, k;
int arr[N][N];

bool ok()
{
	for (int i = 2; ; ++i)
	{
		ll tmp = (ll)i * (i - 1) / 2;
		if (tmp > n) return false;
		if (tmp == n) 
		{
			k = i;
			return true;
		}
	}
	return false;
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		if (n == 1)
		{
			puts("Yes");
			puts("2");
			puts("1 1");
			puts("1 1");
			continue;
		}
		if (!ok()) puts("No"); 
		else
		{
			puts("Yes");
			for (int i = 1, cnt = 0; i < k; ++i)
			{
				for (int j = 1; j <= i; ++j)
					arr[i][j] = ++cnt; 
			}
			printf("%d\n", k);
			for (int i = 1; i < k; ++i)
			{
				printf("%d ", k - 1);
				vector <int> v;
				for (int j = 1; j <= i; ++j) v.push_back(arr[i][j]);
				for (int j = i + 1; j < k; ++j) v.push_back(arr[j][i]);
				for (int i = 0; i < k - 1; ++i) printf("%d%c", v[i], " \n"[i == k - 2]);
			}
			printf("%d ", k - 1);
			for (int i = 1; i < k; ++i) printf("%d%c", arr[i][i], " \n"[i == k - 1]);
		}
	}
}
