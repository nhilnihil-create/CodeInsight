#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n, m;
	cin >> n >> m;
	map<int, int> M;
	int k;
	int a;
	for (int i = 0; i < n; ++i)
	{
		cin >> k;
		for (int j = 0; j < k; ++j)
		{
			cin >> a;
			++M[a];
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i)
	{
		ans += (M[i] == n);
	}
	cout << ans << endl;
	return 0;
}