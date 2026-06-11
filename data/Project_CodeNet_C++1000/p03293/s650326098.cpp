#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	string s, t, ss;
	cin >> s >> t;
	ss = s + s;
	cout << ((ss.find(t) == string::npos)?"No":"Yes") << endl;
	return 0;
}