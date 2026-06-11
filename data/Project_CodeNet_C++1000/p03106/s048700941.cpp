#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

long gcd(long a, long b)
{
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

int  main()
{
	int a ,b,k;
	cin >> a >> b >> k;
	int max = gcd(a, b);
	int i = max;
	int cnt = 0;
	while (i > 0)
	{
		if (a % i == 0 && b % i == 0)
			cnt++;
		if (cnt == k)
			break ;
		i--;
	}
	cout << i << endl;
	return (0);
}