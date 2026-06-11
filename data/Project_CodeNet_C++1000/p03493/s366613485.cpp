#include <iostream>
#include <vector>
using namespace std;
typedef long long int LLI;

int main()
{
	string s;
	cin >> s;
	int sum = 0;
	for(int i = 0; i < s.size(); i++)
		if( s[i] == '1' )
			sum++;
	cout << sum;
}