#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 200005;
const int INF = 1001001001;

int a[MAXN];

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int v = -1, d = INF;
	for (int i = 1; i < n; i++)
		if (abs(2 * a[i] - a[n]) < d)
			d = abs(2 * a[i] - a[n]), v = a[i];
	cout << a[n] << " " << v << endl;
	return 0;
}
