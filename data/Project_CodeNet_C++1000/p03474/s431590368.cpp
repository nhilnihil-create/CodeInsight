#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int a, b;
	string s;
	cin >> a >> b >> s;
	bool ok = 1;
	for (int i = 0; i < a; ++i)
	{
		ok *= ('0' <= s[i] && s[i] <= '9');
	}
	ok *= (s[a] == '-');
	for (int i = a+1; i < s.size(); ++i)
	{
		ok *= ('0' <= s[i] && s[i] <= '9');
	}
	cout << (ok?"Yes":"No") << endl;
	return 0;
}