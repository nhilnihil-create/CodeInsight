#include <bits/stdc++.h>
using namespace std;

int main() {
	string s="    ";
	for(int i = 0;i < 4;i++)
	{
		cin >> s.at(i);
	}
	sort(s.begin(),s.end());
	string k = "NO";
	if(s == "1479")
	{
		k = "YES";
	}
	cout << k <<endl;
	return 0;
}
