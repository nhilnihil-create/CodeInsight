#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int N, T;
	cin >> N >> T;
	int c[100 + 5];
	int t[100 + 5];
	for (int i = 0; i < N; i++)
	{
		cin >> c[i] >> t[i];
	}
	int min = 0;
	for (int i = 0; i < N; i++)
	{
		if (min == 0 && t[i] <= T)
			min = c[i];
		if (t[i] <= T && c[i] < min)
			min = c[i];
		
		
	}
	
	if (min == 0)
		cout << "TLE";
	else
		cout << min;
	

	
	return 0;
}