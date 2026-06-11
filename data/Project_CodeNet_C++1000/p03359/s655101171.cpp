#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int a ,b; cin >> a >> b;
	if (a <= b)
		cout << a << endl;
	else
		cout << a-1 << endl;
	return (0);
}
