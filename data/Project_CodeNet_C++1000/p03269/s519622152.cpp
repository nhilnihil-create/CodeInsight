//#pragma GCC optimize(2)
//#pragma GCC optimize(3,"Ofast","inline")


#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
//#include<unordered_map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
#include<bitset>
using namespace std;
typedef long long ll; 
typedef unsigned int ull; 
typedef pair<ll, ll> pll; 
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
struct ed{
	int to, nxt, w;
}e[N << 1];
int head[N], tot = 1;
void add(int u, int v){
	e[tot].to = v, e[tot].nxt = head[u], head[u] = tot++;
}

int l, n, m;
int a[60][3];
int  main()
{
	while (~scanf("%d", &l))
	{
		m = 0;
		n = 0;
		if (!l)
		{
			a[m][0] = 1;
			a[m][1] = 2;
			a[m][2] = 0;
			m++;
		}
		else if (l <= (1 << 19))
		{
			while ((1 << n) <= l)
				n++;
			for (int i = 1; i < n; i++)
			{
				a[m][0] = i;
				a[m][1] = i + 1;
				a[m][2] = 0;
				m++;
				a[m][0] = i;
				a[m][1] = i + 1;
				a[m][2] = 1 << (i - 1);
				m++;
			}
			for (int i = n - 1, j = 1 << (n - 1); i >= 1; i--)
			{
				if (j + (1 << (i - 1)) <= l)
				{
					a[m][0] = i;
					a[m][1] = n;
					a[m][2] = j;
					m++;
					j += 1 << (i - 1);
				}
			}
			
		}
		else
		{
			n = 20;
			for (int i = 1; i < n; i++)
			{
				a[m][0] = i;
				a[m][1] = i + 1;
				a[m][2] = 0;
				m++;
				a[m][0] = i;
				a[m][1] = i + 1;
				a[m][2] = 1 << (i - 1);
				m++;
			}
			for (int i = n - 1, j = 1 << (n - 1); i >= 1; i--)
			{
				while (j + (1 << (i - 1)) <= l)
				{
					a[m][0] = i;
					a[m][1] = n;
					a[m][2] = j;
					m++;
					j += 1 << (i - 1);
				}
			}
		}
		printf("%d %d\n", n, m);
		for (int i = 0; i < m; i++)
			printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
	}
}