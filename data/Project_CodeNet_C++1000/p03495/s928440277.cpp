#include<bits/stdc++.h>
using namespace std;

int basket[200001];
int main()
{
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int a; cin >> a;
		basket[a]++;
	}
	sort(basket, end(basket));
	int c = 0;
	for (int i = 0; i < 200001; ++i)
		if(basket[i])
			c++;
	c -= k;
	if (c <= 0)
	{
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < 200001 && c; ++i)
	{
		if (basket[i]) 
		{
			ans += basket[i];
			c--;
		}
	}
	cout << ans << endl;
}

