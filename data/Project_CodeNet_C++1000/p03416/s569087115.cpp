#include <bits/stdc++.h>
using namespace std;
typedef long long int LLI;

bool palindrom(int x)
{
	string s = "";
	while( x > 0 )
	{
		s = (char)(x%10+'0') + s;
		x /= 10;
	}
	for(int i = 0; i < s.size()/2; i++)
		if( s[i] != s[s.size()-1-i] )
			return false;
	return true;
}

int main()
{
	int a, b;
	int sum = 0;
	cin >> a >> b;
	for(int i = a; i <= b; i++)
		if( palindrom(i) )
			sum++;
	cout << sum;
}