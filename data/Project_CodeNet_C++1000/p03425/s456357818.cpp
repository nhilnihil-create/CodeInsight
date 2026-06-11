#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int LLI;


int main()
{
	int n;
	cin >> n;
	
	string s;
	LLI arr[5]{};
	LLI sum = 0;
	
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		if( s[0] == 'M' )
			arr[0]++;
		else if( s[0] == 'A' )
			arr[1]++;
		else if( s[0] == 'R' )
			arr[2]++;
		else if( s[0] == 'C' )
			arr[3]++;
		else if( s[0] == 'H' )
			arr[4]++;
	}
	for(int i = 0; i < 3; i++)
		for(int j = i+1; j < 4; j++)
			for(int k = j+1; k < 5; k++)
				sum += arr[i]*arr[j]*arr[k];
	cout << sum;
}