#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	int N, Y;
	cin >> N >> Y;

	int c[3] = {};
	int total;
	int ans[3] = { -1, -1, -1 };
	bool find = false;
	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= (N - i); ++j)
		{
			total = 10000 * i + 5000 * j + 1000 * (N - i - j);
			if (total == Y)
			{
				ans[0] = i;
				ans[1] = j;
				ans[2] = N - i - j;
				find = true;
				break;
			}
		}
		
		if (find) break;
	}

	cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
	return 0;
}