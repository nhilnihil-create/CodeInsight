#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 4;
int a[N];
map <int, int> cnt;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}

	sort(a + 1, a + 1 + n);
	int ans = 0;
	for(int i = n; i >= 1; i--)
	{
		if(cnt[a[i]] == 0)
			continue;
		cnt[a[i]]--;
		for(int j = 30; j >= 0; j--)
		{
			if((1 << j) < a[i])
				break;
			if(cnt[(1 << j) - a[i]] > 0)
			{
				ans++;
				cnt[(1 << j) - a[i]]--;
			}
		}
	}
	cout << ans;
}