#include <algorithm>
#include <cmath>
#include <iostream>
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
	int N;
	cin >> N;

	int ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		int just_e = 0;
		if (i % 2 == 1)
		{
			for (int j = 1; j <= i; ++j)
			{
				if (i % j == 0)
				{
					just_e += 1;
				}
			}
		}

		if (just_e == 8)
		{
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}