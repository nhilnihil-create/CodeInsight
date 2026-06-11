#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
int mx[] = {-1, 1, 0, 0}, my[] = {0, 0, -1, 1};

int n;
int z, w;
int a[3000];

int main()
{
	cin >> n;
	cin >> z >> w;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	if (n == 1)
	{
		cout << abs(a[0] - w);
	}
	else
	{
		cout << max(abs(a[n - 2] - a[n - 1]), abs(a[n - 1] - w));
	}
}