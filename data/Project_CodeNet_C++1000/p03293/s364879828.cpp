#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
string check( string s, string t)
{
	int tmp, j;
	for(int i = 0; i < s.size(); i++)
	{
		for(j = 0; j < s.size(); j++)
		{
			tmp = i+j < s.size() ? i+j : i+j - s.size();
			if( s[j] != t[tmp] )
				break;
		}
		if( j == s.size() )
			return "Yes";
	}
	return "No";
}
int main()
{
	string s, t;
	cin >> s >> t;
	cout << check(s,t);
}