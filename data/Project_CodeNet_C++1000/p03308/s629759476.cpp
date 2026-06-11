#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int tmp, min, max;
	cin >> tmp;
	min = max = tmp;
	for(int i = 1; i < n; i++)
	{
		cin >> tmp;
		if( tmp > max )
			max = tmp;
		if( tmp < min )
			min = tmp;
	}
	cout << abs(max-min);
}