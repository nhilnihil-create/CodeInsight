#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	string a,b; cin >> a >> b;

	if (a[0] == b[2] && a[1] == b[1] && a[2] == b[0])
	{
		cout << "YES\n";
	}
	else 
		cout << "NO\n";
	return (0);
}