#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
	int n, y;
	cin >> n >> y;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			int rem = y - 10000*i - 5000*j;
			if (rem < 0) continue;
			int k = rem / 1000;
			if (i+j+k == n) {
				cout << i << ' ' << j << ' ' << k << endl;
				return 0;
			}
		}
	}
	cout << -1 << " " << -1 << " " << -1 << endl;
	return 0;
}