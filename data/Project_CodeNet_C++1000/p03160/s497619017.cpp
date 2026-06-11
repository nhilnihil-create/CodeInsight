#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int>a(n);
	for (auto &it : a)
		cin >> it;
	vector<int>ans(n);
	ans[0] = 0;
	ans[1] = abs(a[0] - a[1]);
	for (int i = 2; i < n; i++)
		ans[i] = min(ans[i - 1] + abs(a[i] - a[i - 1]), ans[i - 2] + abs(a[i] - a[i - 2]));
	cout << ans[n - 1];

	return 0;
}