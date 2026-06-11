#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;
string yes = "Yes\n";
string no = "No\n";

int  main()
{
	int a,b,c; cin >> a >> b >> c;
	if (a == b)
		cout << c;
	else if (a == c)
		cout << b;
	else if (b == c)
		cout << a;
	return (0);
}