#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
	LLI n, x;
	cin >> n >> x;
	
	LLI tmp, min;
	
	cin >> tmp;
	x -= tmp;
	min = tmp;
	
	for(int i = 1; i < n; i++)
	{
		cin >> tmp;
		if( min > tmp )
			min = tmp;
		x -= tmp;
	}
	cout << n + x/min;
}
