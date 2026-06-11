#include <iostream>
using namespace std;
int main()
{
	int sum = 0;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if( s[i] == '-' )
			sum--;
		else sum++;
	}
	cout << sum;
}