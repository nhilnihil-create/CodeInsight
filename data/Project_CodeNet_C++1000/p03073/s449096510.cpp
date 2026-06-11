#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int na = 0;
	int nb = 0;
	for (int i = 0; i < s.size(); i += 2)
	{
		na += (s[i] == '1');
		nb += (s[i] == '0');
	}
	for (int i = 1; i < s.size(); i += 2)
	{
		na += (s[i] == '0');
		nb += (s[i] == '1');
	}
	cout << min(na, nb) << endl;
	return 0;
}