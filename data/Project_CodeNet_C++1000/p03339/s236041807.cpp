#include <iostream>
using namespace std;
int main()
{
	int n, sum = 0, min;
	string s;
	cin >> n >> s;
	for(int i = 1; i < n; i++)
		if( s[i] == 'E' )
			sum++;
	min = sum;
	for(int i = 0; i < n-1; i++)
	{
		if( s[i] == 'W' )
			sum++;
		if( s[i+1] == 'E' )
			sum--;
		if( min > sum )
			min = sum;
	}
	cout << min;
}