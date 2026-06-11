#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int  main()
{
	string s; cin >> s;
	rep(i, 3)
	{
		if (s[i] == '1')
			s[i] += 8;
		else if (s[i] == '9')
			s[i] -= 8;
	}
	cout << s << endl;
	return (0);
}
