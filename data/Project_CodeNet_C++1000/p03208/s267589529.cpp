#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int h[100001];
	for (int i = 0; i < n; ++i)
	{
		cin >> h[i];
	}
	sort(h, h + n);
	int mi = (1<<30)-1;
	for (int i = 0; i < n - k + 1; ++i)
	{
		mi = min(mi, h[i + k - 1] - h[i]);
	}
	cout << mi << endl;
	return 0;
}