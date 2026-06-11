#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

int  main()
{
	char a,b; cin >> a >> b;
	if (a == b)
		cout << "=\n";
	else if (a < b)
		cout << "<\n";
	else
		cout << ">\n";
	return (0);
}
