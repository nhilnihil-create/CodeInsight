#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
using namespace std;

const int maxM = 200005;
int parent[maxM];
int sum[maxM];

int Find(int x)
{
	if (x != parent[x])
	{
		int i = parent[x];
		parent[x] = Find(parent[x]);
		sum[x] += sum[i];
	}
	return parent[x];
}


int main()
{
	int m, n;
	int ans = 0,flag = 0;
	scanf("%d%d", &m, &n);
		for (int i = 0; i <= m; i++)
		{
			parent[i] = i;
			sum[i] = 0;
		}
		while (n--)
		{
			int l, r, value;
			cin >> l >> r >> value;
			int fl = Find(l);
			int fr = Find(r);
			if (fl == fr)
			{
				if ((sum[l] - sum[r]) != value)
				{
					flag = 1;
				}
			}
			else {
				parent[fl] = fr;
				sum[fl] = -sum[l] + sum[r] + value;
			}
		}
		if(flag)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }

	return 0;
}
