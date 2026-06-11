#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int s; cin >> s;
	if (s == 25)
		cout << "Christmas\n";
	else if (s == 24)
		cout << "Christmas Eve\n";
	else if (s == 23)
		cout << "Christmas Eve Eve\n";
	else if (s == 22)
		cout << "Christmas Eve Eve Eve\n";
	return (0);
}