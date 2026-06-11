#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int n; cin >> n;
	long double sum = 0;
	rep(i, n)
	{
		string u;
		long double x;
		cin >> x >> u;
		if (u == "JPY")
			sum += x;
		else
			sum += (x * 380000.0);
	}
	printf("%Lf\n", sum);
	return (0);
}
