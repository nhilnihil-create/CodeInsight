#include <bits/stdc++.h>
#define INF 1145141919
using namespace std;
 
int main()
{
	int n, k, a[100001];
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	int r = k;
	int ans = 0;
	while(r < n) {
		r += k - 1;
		++ans;
	}
	cout << ans + 1 << endl;
	return 0;
}