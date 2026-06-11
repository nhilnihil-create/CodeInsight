#define alphanso                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL)
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main()
{
        alphanso;
	int n, i, ans = 0;
	cin >> n;
	int v[n], c[n];
	for (i = 0; i < n; i++)
		cin >> v[i];
	for (i = 0; i < n; i++)
		cin >> c[i];
	for (i = 0; i < n; i++)
	{
		if (v[i] >= c[i])
			ans += (v[i] - c[i]);
	}
	cout << ans << endl;
}
