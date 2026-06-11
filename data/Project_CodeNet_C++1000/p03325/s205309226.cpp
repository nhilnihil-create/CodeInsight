#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	vector<int> a;
	int in;
	for (int i = 0; i < n; ++i)
	{
		cin >> in;
		a.push_back(in);
	}
	int ans = 0;
	for (auto &v : a)
	{
		while(v % 2 == 0)
		{
			++ans;
			v /= 2;
		}
	}
	cout << ans << endl;
	return 0;
}