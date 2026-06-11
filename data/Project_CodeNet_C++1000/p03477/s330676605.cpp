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
	int a,b,c,d; cin >> a >> b >> c >> d;
	if (a + b > c + d)
		cout << "Left\n";
	else if (a + b < c + d)
		cout << "Right\n";
	else 
		cout << "Balanced\n";
	return (0);
}