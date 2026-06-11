#include<bits/stdc++.h>
using namespace std;


int main()
{
	string s; cin >> s;
	bool ok = true;
	if (s[0] != 'A') ok = false;
	int c = 0;
	for (int i = 2; i < s.size()-1; ++i)
		if (s[i] == 'C') c++;
	if (c != 1) ok = false;
	int d = 0;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] < 97) d++;
	if (d != 2) ok = false;
	cout << (ok ? "AC" : "WA") << endl;
}

