#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	long long int n, x;
	cin >> n >> x;
	long long int ans = 0, in;
	long long int okashi[101];
	for (long long int i = 0; i < n; ++i)
	{
		cin >> okashi[i];
	}
	sort(okashi, okashi + n);
	for (long long int i = 0; i < n - 1; ++i)
	{
		x -= okashi[i];
		ans += (x >= 0);
	}
	cout << ans + (x == okashi[n - 1]) << endl;
	return 0;
}