#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
 
using namespace std;
 
typedef long long ll;
 
const ll INF = 1e9, MOD = 1e9 + 7;

ll n, d[5001][5001], A, B;

int main ()
{
	cin >> n >> A >> B;

	for (ll i = 1; i <= n; i++)
	{
		ll a;

		scanf ("%lld", &a);

		for (ll j = 0; j <= n; j++)
		{
			if (j < a) d[i][j] = d[i-1][j] + A;
			else if (j == a) d[i][j] = d[i-1][j];
			else d[i][j] = d[i-1][j] + B;
			if (j) d[i][j] = min (d[i][j], d[i][j-1]);
		}
	}

	cout << d[n][n];
}