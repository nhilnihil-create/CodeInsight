#include <bits/stdc++.h>
using namespace std;
int  main()
{
	string s; cin >> s;
	if (stoi(s.substr(5, 2)) < 5) cout << "Heisei" << endl;
	else  cout << "TBD" << endl;
	return (0);
}
