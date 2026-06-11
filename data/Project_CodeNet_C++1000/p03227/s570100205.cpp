#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	if(s.length() == 2)
	{
		cout << s;
	}
	else
	{
		cout << s.at(2) << s.at(1) << s.at(0);
	}
	cout << endl;
	return 0;
}
