#include<bits/stdc++.h>

using namespace std;

#define N (2 << 18)

int n;

pair<int, int> f[N];

pair<int, int> merge(pair<int, int> a, pair<int, int> b)
{
	if(b.first > a.first) swap(a, b);
	pair<int, int> ans = a;
	if(b.first > ans.second) ans.second = b.first;
	return ans;
}

int main()
{
	scanf("%d", &n);
	int all = (1 << n);
	for(int i = 0; i < all; i++) 
	{
		int x;
		scanf("%d", &x);
		f[i] = make_pair(x, 0);
	}
	for(int j = 0; j < n; j++)
		for(int i = 0; i < all; i++)
			if(i >> j & 1) f[i] = merge(f[i], f[i ^ (1 << j)]);
	int ans = 0;
	for(int i = 1; i < all; i++)
	{
		ans = max(ans, f[i].first + f[i].second);
		printf("%d\n", ans);
	}
	return 0;
}