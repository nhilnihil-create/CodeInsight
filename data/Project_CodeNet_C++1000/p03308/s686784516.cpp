#include <iostream>
using namespace std;


int main() {

	int count = 0, count_max = 0;
	int tmp;
	int i;

	int N;
	

	cin >> N;
	long int a[N], a_max, a_min;
	
	for ( i = 0; i < N; i++)
	{
		cin >> a[i];

		if (i == 0)
		{
			a_min = a[i];
			a_max = a[i];
		}
		else
		{
			if (a[i] < a_min)
			{
				a_min = a[i];
			}
			else if(a[i] > a_max)
			{
				a_max = a[i];
			}
			
			
		}
	
	}
	
	long int a_out = a_max-a_min;
		
		cout << a_out << endl;
		
	
	
}