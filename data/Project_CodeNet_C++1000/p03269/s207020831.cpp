#include "bits/stdc++.h"
using namespace std;
int main()
{
	int l, n = 19;
	scanf("%d", &l);
	for(int i = 1 << n; i > l; i = 1 << --n){}
	vector<vector<int>> a(0, vector<int>(3));
	for(int i = 0; i < n; ++i)
	{
		a.push_back(vector<int>{i, i + 1, 0});
		a.push_back(vector<int>{i, i + 1, 1 << i});
	}
	for(int i = n - 1; i >= 0; --i)
	{
		if(l - (1 << i) >= 1 << n)
		{
			a.push_back(vector<int>{i, n, l -= (1 << i)});
		}
	}
	printf("%d %d\n", n + 1, a.size());
	for(vector<int> i : a)
	{
		printf("%d %d %d\n", i[0] + 1, i[1] + 1, i[2]);
	}
}