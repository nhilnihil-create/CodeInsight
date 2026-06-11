#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, x;
	cin >> n >> m >> x;
	vector<int> as(m);
	for (auto &&a : as)
	{
		cin >> a;
	}

	cout << min(distance(as.begin(), lower_bound(as.begin(), as.end(), x)), distance(upper_bound(as.begin(), as.end(), x), as.end())) << endl;

	return 0;
}