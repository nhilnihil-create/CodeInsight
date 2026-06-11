#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#define PRE std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
const int Mod = 1e9 + 7;
int lst[Max][2], f[Max];
int ls[Max];

void init(int n)
{
	for (int i = 1;i <= n;i++) f[i] = i;
}

int getf(int a)
{
	if (a != f[a])return f[a]=getf(f[a]);
	return a;
}

void merge(int a, int b)
{
	f[a] = getf(a);
	f[b] = getf(b);
	if (f[b] != f[a]) f[f[b]] = f[a];
}

int main()
{
	PRE;
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= m;i++)
	{
		cin >> lst[i][0] >> lst[i][1];
	}
	int res = 0;
	for (int i = 1;i <= m;i++)
	{
		init(n);
		for (int j = 1;j <= m;j++)
		{
			if (i == j)continue;
			merge(lst[j][0], lst[j][1]);
		}
		int sum = 0;
		for (int k = 1;k <= n;k++)
		{
			getf(k);
			if (f[k] == k)sum++;
		}
		if (sum >= 2)res++;
	}
	cout << res;
}