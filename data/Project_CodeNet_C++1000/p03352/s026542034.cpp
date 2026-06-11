#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int x, tmp, max = 1;
	cin >> x;
	if( x == 1 )
		cout << 1;
	else{
		for(int i = 2; i*i <= x; i++)
		{
			tmp = 1;
			while( tmp <= x )
				tmp *= i;
			tmp /= i;
			if( tmp > max )
				max = tmp;
		}
		cout << max;
	}
}