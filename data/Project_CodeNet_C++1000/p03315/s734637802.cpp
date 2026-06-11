#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	string s;
	int a = 0;
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
	{
		a += ((s[i] == '+')?1:-1);
	}
	cout << a << endl;
	return 0;
}