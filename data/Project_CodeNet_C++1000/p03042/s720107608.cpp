#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int  main()
{
	string s;
	cin >> s;
	int a,b;
	a = stoi(s.substr(0, 2));
	b = stoi(s.substr(2, 2));
	// cout << a <<  endl;
	// cout << b <<  endl;
	if ((a == 0 && b > 12) || (b == 0 && a > 12) || (a > 12 && b > 12) || (a==0 && b==0))
		cout << "NA\n";
	else if (!(a >= 1 && a <=12) && (b >= 1 && b <= 12))
		cout << "YYMM\n";
	else if ((a >= 1 && a <=12) && !(b >= 1 && b <= 12))
		cout << "MMYY\n";
	else if ((a >= 1 && a <=12) && (b >= 1 && b <= 12))
		cout << "AMBIGUOUS\n";
	return (0);
}
