#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int  main()
{
	string s; cin >> s;
	if (s[0] == s[1] == s[2])
		cout << s << endl;
	else
	{
		if (stoi(s) <= 111)
			cout << 111;
		else if (stoi(s) <= 222)
			cout << 222;
		else if (stoi(s) <= 333)
			cout << 333;
		else if (stoi(s) <= 444)
			cout << 444;
		else if (stoi(s) <= 555)
			cout << 555;
		else if (stoi(s) <= 666)
			cout << 666;
		else if (stoi(s) <= 777)
			cout << 777;
		else if (stoi(s) <= 888)
			cout << 888;
		else if (stoi(s) <= 999)
			cout << 999;
	}
	return (0);
}
