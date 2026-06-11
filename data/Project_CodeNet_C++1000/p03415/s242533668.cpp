#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	string s[3];
	rep(i, 3)
		cin >> s[i];
	cout << s[0][0] << s[1][1] << s[2][2] << endl;
	return (0);
}
