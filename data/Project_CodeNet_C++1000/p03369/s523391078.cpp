#include <iostream>
#include <cmath>
using namespace std;
typedef long long int LLI;
int main()
{
	string s;
	cin >> s;
	int sum = 700;
	for(int i = 0; i < s.size(); i++)
	{
		if( s[i] == 'o' )
			sum += 100;
	}
	cout << sum;
}
