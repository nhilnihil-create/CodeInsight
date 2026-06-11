#include <iostream>
#include <cmath>
using namespace std;
typedef long long int LLI;

int main()
{
	int n;
	cin >> n;
	
	LLI arr[2][n];
	cin >> arr[0][0];
	
	LLI top = arr[0][0], bottom = 0, max = 0;
	for(int i = 1; i < n; i++)
		cin >> arr[0][i];
	
	for(int i = 0; i < n; i++)
	{
		cin >> arr[1][i];
		bottom += arr[1][i];
	}

	if( bottom + top > max )
		max = bottom + top;
		
	for(int i = 1; i < n; i++)
	{
		top += arr[0][i];
		bottom -= arr[1][i-1];
		if( bottom + top > max )
			max = bottom + top;
	}
	cout << max;
}