#include <bits/stdc++.h>

using namespace std;

map <int,int> d;

int main() 
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	string s;
	
	cin >> s;
	
	cout << s.substr(0,s.length() - 8) << '\n';
	
	return 0;
}