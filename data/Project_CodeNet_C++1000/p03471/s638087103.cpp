#include <iostream>
#include <string>
using namespace std;


int main() {

	int count = 0, count_max = 0;
	long int tmp;
	int i, j;

	long int N, Y;
	int x = -1, y = -1, z = -1;

	cin >> N;
	cin >> Y;
	
	for ( i = 0; i <= N; i++)
	{
		for ( j = 0; j <= N-i; j++)
		{
			tmp = i*5000 + j*1000 + (N-i-j)*10000;

			if (tmp == Y)
			{
				x = N - (i+j);
				y = i;
				z = j;
				i = N+1;
				break;
			}
			
		}
		
	}
	
	
	

	cout << x << " " <<  y << " " << z << " "  << endl;
	
		
	
	
}