#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x;
	cin >> x;
	vector<int> ans;
	for (int i = 1; i <= 10000; ++i)
	{
		for (int j = 2; j < 10000; ++j)
		{
			if (pow(i, j) > x)
			{
				break;
			}
			ans.push_back(pow(i, j));
		}
	}
	sort(ans.begin(), ans.end(), greater<int>());
	cout << ans[0] << endl;
	return 0;
}