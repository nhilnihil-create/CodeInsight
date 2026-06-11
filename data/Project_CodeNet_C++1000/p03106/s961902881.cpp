#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int  main()
{
	int a ,b, k;
	cin >> a >> b >> k;
	int i = min(a,b);
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
