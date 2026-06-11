#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long ll;

int  main()
{
	int a,b,c; cin >> a >> b >> c;
	priority_queue<int> q;
	int x = abs(a - b); 
	int y = abs(b - c);
	int z = abs(a - c);
	q.push(x); q.push(y); q.push(z);
	q.pop();
	int ans = q.top(); q.pop();
	ans += q.top();
	cout << ans << endl;
	return (0);
}
