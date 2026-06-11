#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int shop_mask[101];
int p[101][11];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 10; j++){
			int a;
			cin >> a;
			if(a == 1)
				shop_mask[i] |= (1 << j);
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 11; j++)
			cin >> p[i][j];
	int ans = INT_MIN;
	for(int mask = 1; mask < (1 << 10); mask++)
	{
		int cur = 0;
		for(int i = 0; i < n; i++)
			cur += p[i][__builtin_popcount(mask & shop_mask[i])];
		ans = max(ans, cur);
	}
	cout << ans;
	return 0;
}
