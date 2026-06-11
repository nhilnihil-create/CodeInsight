#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (abs (a - c) <= d)
	{
		cout << "Yes\n";
	}
	else if (abs(a-b) <= d && abs(b-c) <= d)
	{
		cout << "Yes\n";
	}
	else 
		cout << "No\n";
	return (0);
}
