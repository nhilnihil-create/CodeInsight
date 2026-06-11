#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int a, b; cin >> a >> b;

	vector <int > q;
	rep1(i, 999)
	{
		int sum = 0;
		for (int j = 1; j <= i; j++)
			sum += j;
		q.push_back(sum);
	}
	rep(i, q.size() -1 )
	{
		if (q[i] - a == q[i+1] - b)
		{
			cout << q[i] - a << endl;
			return 0;
		}
	}
	return (0);
}
