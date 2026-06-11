#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int n; cin >> n;
	priority_queue<int> q;
	int sum = 0;
	rep(i, n)
	{
		int p; cin >> p;
		sum += p;
		q.push(p);
	}
	sum -= q.top();
	sum += q.top()/2;
	cout << sum << endl;
	return (0);
}